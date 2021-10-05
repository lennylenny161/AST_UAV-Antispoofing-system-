import sys
import rclpy
import threading
import functools
import configparser
import datetime
import copy
import logging
import queue
from rclpy.node import Node
from collections import deque
from interfaces.msg import SpoofingControl
from interfaces.msg import Ins
from interfaces.msg import AnalyzerCallback
from .FileReader import *
from .simulator import *
from .database import *
from .clientTest import *

class SimulatorCallbackPublisher(Node):
    def __init__(self):
        super().__init__('simulator_publisher_class')
        self.publisher_ = self.create_publisher(AnalyzerCallback, 'simulator_topic', 10)

    def callback(self, data):
        msg = AnalyzerCallback()
        msg.check_result = data.check_result
        msg.error_code = data.error_code
        msg.error_description = data.error_description
        print("SEND CALLBACK", msg)
        self.publisher_.publish(msg)

class SpoofingControlSubscriber(Node):

    on_state = bytes('1', 'utf-8')
    off_state = bytes('0', 'utf-8')

    def __init__(self, topic_name, control_state):
        super().__init__(topic_name)
        callback_lambda = lambda x: self.listener_callback(x, control_state)
        self.subscription = self.create_subscription(
            SpoofingControl,
            topic_name,
            callback_lambda,
            10)
        self.subscription

    def listener_callback(self, msg, control_state):
        if msg.spoof_cntrl_state.decode('utf-8') == '1':
            control_state[0] = self.on_state
            self.get_logger().info('Send ON')
        else:
            control_state[0] = self.off_state
            self.get_logger().info('Send OFF')

class DataSubscriber(Node):

    def __init__(self, topic_name, control_state):
        super().__init__("data_node")
        q = queue.Queue()
        threading.Thread(target=self.queue_loop_reader, args=(q,), daemon=True).start()
        self.data_buffer = self.get_simulate_data_size()
        callback_lambda = lambda x: self.listener_callback(x, control_state, q)
        self.subscription = self.create_subscription(
            Ins,
            topic_name,
            callback_lambda,
            10)
        self.subscription

    def listener_callback(self, msg, control_state, q):

        data = self.parse_msg_to_data(msg)
        self.save_data_buffer(data)

        timestamp = msg.header.stamp.sec + (msg.header.stamp.nanosec / 1000000000)
        round_value = round(timestamp, 5)

        if control_state[0].decode('utf-8') == '1':
            print("ATTACK")
            logging.info('catch attack state time = %s', str(timestamp))

            threading.Thread(target=self.add_data_in_queue, args=(q, data, round_value, 1,)).start()
            # simulate_value = self.simulate()
            # threading.Thread(target=self.create_callback_pub(simulate_value)).start()
        else:
            threading.Thread(target=self.add_data_in_queue, args=(q, data, round_value, 0,)).start()

        # self.get_logger().info('Subscribe data: status "%a" '
        #                        ' pitch "%f" '
        #                        ' roll "%f" '
        #                        ' course "%f" '
        #                        ' w_x "%f"'
        #                        ' w_y "%f"'
        #                        ' w_z "%f"'
        #                        ' a_x "%f"'
        #                        ' a_y "%f"'
        #                        ' a_z "%f"'
        #                        ' gps_speed "%f"'
        #                        ' gps_track_angle "%f"'
        #                        ' gps_satellite_number "%f"'
        #                        ' altitude "%f"'
        #                        ' latitude "%f"'
        #                        ' longitude "%f"'
        #                        ' gps_utc_date "%f"'
        #                        ' utc_time "%f"'
        #                        ' targeting "%i"'
        #                        ' temperature "%i"'%
        #                        (msg.status,
        #                         msg.pitch,
        #                         msg.roll,
        #                         msg.course,
        #                         msg.w_x,
        #                         msg.w_y,
        #                         msg.w_z,
        #                         msg.a_x,
        #                         msg.a_y,
        #                         msg.a_z,
        #                         msg.gps_speed,
        #                         msg.gps_track_angle,
        #                         msg.gps_satellite_number,
        #                         msg.altitude,
        #                         msg.latitude,
        #                         msg.longitude,
        #                         msg.gps_utc_date,
        #                         msg.utc_time,
        #                         msg.targeting,
        #                         msg.temperature))

    def add_data_in_queue(self, q, data, time, beFake):
        print("ADD TO QUEUE")
        q.put([data, time, beFake])

    def queue_loop_reader(self, q):
        conn = DatabaseWorker().create_connection()
        while True:
            if q.empty():
                pass
            else:
                print("GETGETGET QUEUE")
                data = q.get()
                DatabaseWorker.write_data(conn, data[0], data[1], data[2])


    def save_data_to_DB(self, data, time, beFake):
        conn = DatabaseWorker().create_connection()
        DatabaseWorker.write_data(conn, data, time, beFake)


    def simulate(self):
        logging.info('simulate data')
        simulator = Simulator()
        new_value = simulator.simulate_new_value(self.data_buffer)
        return new_value

    def parse_msg_to_data(self, msg: Ins):
        data = ControllerDataClass()
        data.status = msg.status
        data.pitch = msg.pitch
        data.roll = msg.roll
        data.course = msg.course
        data.w_x = msg.w_x
        data.w_y = msg.w_y
        data.w_z = msg.w_z
        data.a_x = msg.a_x
        data.a_y = msg.a_y
        data.a_z = msg.a_z
        data.gps_speed = msg.gps_speed
        data.gps_track_angle = msg.gps_track_angle
        data.gps_satellite_number = msg.gps_satellite_number
        data.altitude = msg.altitude
        data.latitude = msg.latitude
        data.longitude = msg.longitude
        data.gps_utc_date = msg.gps_utc_date
        data.utc_time = msg.utc_time
        data.targeting = msg.targeting
        data.temperature = msg.temperature

        return data

    def save_data_buffer(self, data):
        self.data_buffer.appendleft(data)
        self.data_buffer.pop()

    def get_simulate_data_size(self):
        config = configparser.ConfigParser()
        config.read("config.ini")
        queue_size = int(config['SimulatorConfig']['queue_size'])
        d = deque([None] * queue_size)
        return d


unsent_data = []
simulator_publisher: SimulatorCallbackPublisher


def get_update_unsent_data_time():
    config = configparser.ConfigParser()
    config.read("config.ini")
    unsent_data_time = int(config['SimulatorConfig']['unsent_data_update_time'])
    return unsent_data_time


def loop_read_database():
    global unsent_data
    while True:
        print(len(unsent_data), "Длинна")
        if len(unsent_data) == 0:
            conn = DatabaseWorker().create_connection()
            data = DatabaseWorker.read_unsent_data(conn)
            print(data, 'DATA')
            if (data != None) :
                unsent_data = data
                #print(len(data), "РАЗМЕР МАССИВА")
                send_data_to_analyzer()
        else:
            print("NOT EMPTY")
        loop_time = 1 # get_update_unsent_data_time()
        time.sleep(loop_time)


def self_spin(client, data):
    print("self_spin")
    global simulator_publisher
    while rclpy.ok():
        rclpy.spin_once(client)
        if client.future.done():
            result = client.future.result() #SENT TO GUI
            print(result, "RESULT")
            logging.info('send data to callback publisher')
            simulator_publisher.callback(result)
            conn = DatabaseWorker().create_connection()
            DatabaseWorker.write_send_mark(conn, data[0], 1)
            client.destroy_node()
            print('SENT', data[0])
            break


def group_call(data):
    name = "AnalyzerClientAsync"
    client = AnalyzerClientAsync(name)
    print("SEND DATA TO SERVER", data)
    client.send_request(data)
    self_spin(client, data)


def send_data_to_analyzer():
    global unsent_data
    copy_data = unsent_data.copy()
    for data in copy_data:
        print('send_data_to_analyzer LOOP')
        group_call(data)
        unsent_data.remove(data)
    print("End Loop")


def main(args=None):
    rclpy.init(args=args)

    Loger.set_type("sim")

    database_thread = threading.Thread(target=loop_read_database)
    database_thread.setDaemon(True)
    database_thread.start()

    spoof_control_state = [bytes('0', 'utf-8')]
    print('MAIN "%a"' % (id(spoof_control_state)))

    global simulator_publisher

    simulator_publisher = SimulatorCallbackPublisher()
    data_subscriber = DataSubscriber('/rtk_1/ins_data', spoof_control_state)
    spoofing_subscriber = SpoofingControlSubscriber('spoofing_control_topic', spoof_control_state)

    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(data_subscriber)
    executor.add_node(spoofing_subscriber)
    executor.add_node(simulator_publisher)

    executor_thread = threading.Thread(target=executor.spin, daemon=True)
    executor_thread.start()
    rate = data_subscriber.create_rate(1) # Потыкать

    try:
        while rclpy.ok():
            rate.sleep()
    except KeyboardInterrupt:
        pass
    rclpy.shutdown()
    executor_thread.join()


if __name__ == '__main__':
    main()
