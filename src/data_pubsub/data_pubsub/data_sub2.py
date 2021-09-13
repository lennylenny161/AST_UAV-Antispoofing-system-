import sys
import rclpy
import threading
import functools
import configparser
import datetime
import copy
from rclpy.node import Node
from collections import deque
from interfaces.msg import SpoofingControl
from interfaces.msg import Ins
from .FileReader import *
from .simulator import *
from .database import *

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
        super().__init__(topic_name)
        self.data_buffer = self.get_simulate_data_size()
        callback_lambda = lambda x: self.listener_callback(x, control_state)
        self.subscription = self.create_subscription(
            Ins,
            topic_name,
            callback_lambda,
            10)
        self.subscription

    def listener_callback(self, msg, control_state):
        print('DataSubscriberControlState "%a"' % (control_state[0]))

        data = self.parse_msg_to_data(msg)
        self.save_data_buffer(data)

        timestamp = msg.header.stamp.sec + (msg.header.stamp.nanosec / 1000000000)
        round_value = round(timestamp, 4)

        if control_state[0].decode('utf-8') == '1':
            print("ATTACK")
            threading.Thread(target=self.save_data_to_DB(data, round_value, 1)).start()
            # simulate_value = self.simulate()
            # threading.Thread(target=self.create_callback_pub(simulate_value)).start()
        else:
            threading.Thread(target=self.save_data_to_DB(data, round_value, 0)).start()

        self.get_logger().info('Subscribe data: status "%a" '
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
                               ' gps_satellite_number "%f"'
                               ' altitude "%f"'
                               ' latitude "%f"'
                               ' longitude "%f"'
                               ' gps_utc_date "%f"'
                               ' utc_time "%f"'
                               ' targeting "%i"'
                               ' temperature "%i"'%
                               (msg.status,
                                msg.pitch,
                                msg.roll,
                                msg.course,
                                msg.w_x,
                                msg.w_y,
                                msg.w_z,
                                msg.a_x,
                                msg.a_y,
                                msg.a_z,
                                msg.gps_speed,
                                msg.gps_track_angle,
                                msg.gps_satellite_number,
                                msg.altitude,
                                msg.latitude,
                                msg.longitude,
                                msg.gps_utc_date,
                                msg.utc_time,
                                msg.targeting,
                                msg.temperature))

    def save_data_to_DB(self, data, time, beFake):
        conn = DatabaseWorker.create_connection()
        DatabaseWorker.write_data(conn, data, time, beFake)


    def simulate(self):
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


def main(args=None):
    rclpy.init(args=args)

    spoof_control_state = [bytes('0', 'utf-8')]
    print('MAIN "%a"' % (id(spoof_control_state)))

    data_subscriber = DataSubscriber('data_topic', spoof_control_state)
    spoofing_subscriber = SpoofingControlSubscriber('spoofing_control_topic', spoof_control_state)

    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(data_subscriber)
    executor.add_node(spoofing_subscriber)

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
