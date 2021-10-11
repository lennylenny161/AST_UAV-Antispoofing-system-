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
from interfaces.msg import AntiSpoofing
from .FileReader import *
from .simulator import *
from .database import *
from .clientTest import *

class FakeDataPublisher(Node):

    def __init__(self):
        super().__init__('fake_data_class')
        self.publisher_ = self.create_publisher(Ins, 'fake_ins_data', 10)

    def callback(self, data):
        msg = Ins()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.status = data.status
        msg.pitch = data.pitch
        msg.roll = data.roll
        msg.course = data.course
        msg.w_x = data.w_x
        msg.w_y = data.w_y
        msg.w_z = data.w_z
        msg.a_x = data.a_x
        msg.a_y = data.a_y
        msg.a_z = data.a_z
        msg.gps_speed = data.gps_speed
        msg.gps_track_angle = data.gps_track_angle
        msg.gps_satellite_number = data.gps_satellite_number
        msg.altitude = data.altitude
        msg.latitude = data.latitude
        msg.longitude = data.longitude
        msg.gps_utc_date = data.gps_utc_date
        msg.utc_time = data.utc_time
        msg.targeting = data.targeting
        msg.temperature = data.temperature

        self.publisher_.publish(msg)


class SimulatorAntiSpoofingPublisher(Node):

    on_state = bytes('1', 'utf-8')
    off_state = bytes('0', 'utf-8')

    def __init__(self):
        super().__init__('simulator_anti_spoofing_class')
        self.publisher_ = self.create_publisher(AntiSpoofing, 'anti_spoofing', 10)

    def callback(self, anal_result, beFake):
        msg = AntiSpoofing()
        if anal_result:
            msg.nav_state = self.on_state
        else:
            msg.nav_state = self.off_state
        if beFake:
            msg.module_state = self.off_state
        else:
            msg.module_state = self.on_state

        # print("SEND CALLBACK", msg)
        self.publisher_.publish(msg)

class SimulatorCallbackPublisher(Node):
    def __init__(self):
        super().__init__('simulator_publisher_class')
        self.publisher_ = self.create_publisher(AnalyzerCallback, 'simulator_topic', 10)

    def callback(self, data):
        msg = AnalyzerCallback()
        msg.check_result = data.check_result
        msg.error_code = data.error_code
        msg.error_description = data.error_description
        #print("SEND CALLBACK", msg)
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

    def __init__(self, topic_name, control_state, q):
        super().__init__("data_node")
        threading.Thread(target=self.queue_loop_reader, args=(q, True, ), daemon=True).start()
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

        logging.info('Real DATA "%f" '
                     ' pitch "%f" '
                     ' roll "%f" '
                     ' course "%f" '
                     ' w_x "%f"'
                     ' w_y "%f"'
                     ' w_z "%f"'
                     ' a_x "%f"'
                     ' a_y "%f"'
                     ' a_z "%f"'
                     ' gps_speed "%f"'
                     ' gps_track_angle "%f"'
                     ' gps_satellite_number "%i"'
                     ' altitude "%f"'
                     ' latitude "%f"'
                     ' longitude "%f"'
                     ' gps_utc_date "%f"'
                     ' utc_time "%f"'
                     ' targeting "%i"'
                     ' temperature "%i"' %
                     (round_value,
                      data.pitch,
                      data.roll,
                      data.course,
                      data.w_x,
                      data.w_y,
                      data.w_z,
                      data.a_x,
                      data.a_y,
                      data.a_z,
                      data.gps_speed,
                      data.gps_track_angle,
                      data.gps_satellite_number,
                      data.altitude,
                      data.latitude,
                      data.longitude,
                      data.gps_utc_date,
                      data.utc_time,
                      data.targeting,
                      data.temperature))

        if control_state[0].decode('utf-8') == '1':
            print("ATTACK")
            logging.info('catch attack state time = %s', str(timestamp))
            simulate_value = self.simulate()
            logging.info('SIMULATE DATA "%f" '
                         ' pitch "%f" '
                         ' roll "%f" '
                         ' course "%f" '
                         ' w_x "%f"'
                         ' w_y "%f"'
                         ' w_z "%f"'
                         ' a_x "%f"'
                         ' a_y "%f"'
                         ' a_z "%f"'
                         ' gps_speed "%f"'
                         ' gps_track_angle "%f"'
                         ' gps_satellite_number "%i"'
                         ' altitude "%f"'
                         ' latitude "%f"'
                         ' longitude "%f"'
                         ' gps_utc_date "%f"'
                         ' utc_time "%f"'
                         ' targeting "%i"'
                         ' temperature "%i"' %
                         (round_value,
                          simulate_value.pitch,
                          simulate_value.roll,
                          simulate_value.course,
                          simulate_value.w_x,
                          simulate_value.w_y,
                          simulate_value.w_z,
                          simulate_value.a_x,
                          simulate_value.a_y,
                          simulate_value.a_z,
                          simulate_value.gps_speed,
                          simulate_value.gps_track_angle,
                          simulate_value.gps_satellite_number,
                          simulate_value.altitude,
                          simulate_value.latitude,
                          simulate_value.longitude,
                          simulate_value.gps_utc_date,
                          simulate_value.utc_time,
                          simulate_value.targeting,
                          simulate_value.temperature))
            threading.Thread(target=self.add_data_in_queue, args=(q, simulate_value, round_value, 1,)).start()
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

    def add_data_in_queue(self, q, data, _time, beFake):
        #print("ADD TO QUEUE")
        _type = "write"
        q.put([_type, data, _time, beFake])

    def choose_database_action(self, q, conn):
        data = q.get()
        if data[0] == "write":
            print("write")
            DatabaseWorker.write_data(conn, data[1], data[2], data[3])
        elif data[0] == "update":
            print("update")
            DatabaseWorker.write_send_mark(conn, data[1], data[2])

    def queue_loop_reader(self, q, loop_value):
        conn = DatabaseWorker().create_connection()
        while loop_value:
            if q.empty():
                pass
            else:
                self.choose_database_action(q, conn)


    def simulate(self):
        logging.info('simulate data')
        simulator = Simulator()
        new_value = simulator.simulate_new_value(self.data_buffer)
        fake_publisher = FakeDataPublisher()
        threading.Thread(target=fake_publisher.callback, args=(new_value,)).start()
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
antispoofing_publisher: SimulatorAntiSpoofingPublisher
data_subscriber: DataSubscriber
q: queue.Queue


def get_update_unsent_data_time():
    config = configparser.ConfigParser()
    config.read("config.ini")
    unsent_data_time = int(config['SimulatorConfig']['unsent_data_update_time'])
    return unsent_data_time


def loop_read_database():
    global unsent_data
    #conn = DatabaseWorker().create_connection()
    while True:
        print(len(unsent_data), "Длинна")
        if len(unsent_data) == 0:
            conn = DatabaseWorker().create_connection()
            data = DatabaseWorker.read_unsent_data(conn)
            print(data, 'DATA')
            if (data != None) :
                if (len(data) != 0):
                    unsent_data = data
                    print("BEfore SEND")
                # print(len(data), "РАЗМЕР МАССИВА")
                    send_data_to_analyzer()
                else:
                    print("EMPTY ARRAY DATA")
        else:
            print("NOT EMPTY")
        loop_time = get_update_unsent_data_time()
        time.sleep(loop_time)


def add_data_in_queue2(_time, status):
    global q
    _type = "update"
    q.put([_type, _time, status])

def self_spin(client, data):
    global simulator_publisher
    global antispoofing_publisher
    global data_subscriber

    while rclpy.ok():
        rclpy.spin_once(client)
        if client.future.done():
            result = client.future.result() #SENT TO GUI
            #print(result, "RESULT")
            logging.info('send data to callback publisher')
            #DatabaseWorker.write_send_mark(conn, data[0], 1)
            simulator_publisher.callback(result)
            antispoofing_publisher.callback(result.check_result, bool(data[21]))
            add_data_in_queue2(data[0], 1)
            client.destroy_node()
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
        group_call(data) #ALARM
        unsent_data.remove(data)
    print("End Loop")


def main(args=None):
    rclpy.init(args=args)

    global q

    Loger.set_type("sim")
    q = queue.Queue()

    database_thread = threading.Thread(target=loop_read_database, daemon=True)
    database_thread.setDaemon(True)
    database_thread.start()

    spoof_control_state = [bytes('0', 'utf-8')]
    print('MAIN "%a"' % (id(spoof_control_state)))

    global simulator_publisher
    global antispoofing_publisher
    global data_subscriber

    simulator_publisher = SimulatorCallbackPublisher()
    antispoofing_publisher = SimulatorAntiSpoofingPublisher()
    data_subscriber = DataSubscriber('/rtk_1/ins_data', spoof_control_state, q)
    spoofing_subscriber = SpoofingControlSubscriber('spoofing_control', spoof_control_state)

    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(data_subscriber)
    executor.add_node(spoofing_subscriber)
    executor.add_node(simulator_publisher)
    executor.add_node(antispoofing_publisher)

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
