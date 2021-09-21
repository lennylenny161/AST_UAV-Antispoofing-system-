from interfaces.srv import AnalyzerServer

import rclpy
from rclpy.node import Node
from datetime import datetime

class AnalyzerService(Node):

    def __init__(self):
        super().__init__('analyzer_service')
        self.srv = self.create_service(AnalyzerServer, 'analyzer_server', self.analyzer_callback)

    def analyzer_callback(self, request, response):
        print(request)
        response.check_result = False
        response.error_code = 5
        current_date = datetime.now()
        response.error_description = str(current_date)

        return response


def main(args=None):
    rclpy.init(args=args)

    analyzer_server = AnalyzerService()

    rclpy.spin(analyzer_server)

    rclpy.shutdown()


if __name__ == '__main__':
    main()