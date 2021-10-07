from interfaces.srv import AnalyzerServer
import json
import math
import logging
import rclpy
from rclpy.node import Node
from datetime import datetime
from .loger import *

INVALID_FORMAT = ['0', 0]


class AnalyzerService(Node):

    def __init__(self):
        super().__init__('analyzer_service')
        setup_file = open('analyse-config.json')
        self.setup = json.load(setup_file)
        self.store = {}
        self.dataset = []
        self.srv = self.create_service(AnalyzerServer, 'analyzer_server', self.analyzer_callback)
        setup_file.close()

    def analyzer_callback(self, request, response):
        print(request)
        self.dataset.append(request)
        self.dataset = self.dataset[-int(self.setup['slice_size']):]
        if len(self.dataset) < self.setup['slice_size']:
            return set_result(response, False, 100, request.time)

        if self.check_invalid_data(request):
            return set_result(response, True, 101, request.time)

        total_score = sum(list(map(lambda field_config: self.field_processing(self.dataset, field_config), self.setup['fields'])))
        error_code = (110, 111)[total_score > self.setup['attack_score']]
        # error_code = ('Normal', 'Attack!')[total_score > setup['attack_score']]
        return set_result(response, True, error_code, request.time)


    def field_processing(self, data, field_config):
        if field_config['score'] == 0:
            return 0

        data_selection = list(map(lambda event: int(getattr(event, field_config['name'])), data))
        #print(data_selection, "DATA_Selection")
        probability = calculate_distribution(data_selection)

        cached_value = self.store.get(field_config['name'])
        entropy_value_1 = entropy(probability, cached_value) if cached_value else 0  # for each in collection
        entropy_value_2 = entropy(cached_value, probability) if cached_value else 0
        self.store[field_config['name']] = probability

        exceeding_1 = abs(entropy_value_1) > field_config['threshold']
        exceeding_2 = abs(entropy_value_2) > field_config['threshold']
        attack_detector = (0, float(field_config['score']))[exceeding_1 or exceeding_2]
        logging.info('[%s]: %f(E1); %f(E2); Probability - %f; Conclusion - %s ',
                     str(field_config['name']), entropy_value_1, entropy_value_2, probability, attack_detector)
        return attack_detector

    def check_invalid_data(self, request):
        for field in self.setup['required_fields']:
            if getattr(request, field) in INVALID_FORMAT:
                logging.warning('Invalid data in field [%s]', str(field))
                return True
            else:
                return False


def set_result(response, check, error_code, description):
    response.check_result = check
    response.error_code = error_code
    response.error_description = str(description)
    return response


def calculate_distribution(collection):
    current_value = abs(collection[-1])
    estimated_value = abs(average(collection))
    distribution = ((math.e ** (estimated_value * -1)) * (estimated_value ** current_value)) / math.factorial(
        current_value)
    return distribution


def entropy(current_value, previous_value):
    return previous_value * (math.log(previous_value / current_value))


def average(collection):
    return sum(collection) / len(collection)


def main(args=None):
    rclpy.init(args=args)
    print("MAIN")
    Loger.set_type("anal")
    analyzer_server = AnalyzerService()

    rclpy.spin(analyzer_server)

    rclpy.shutdown()


if __name__ == '__main__':
    main()
