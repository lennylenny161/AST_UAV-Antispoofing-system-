from interfaces.srv import AnalyzerServer
import sys
import rclpy
from rclpy.node import Node
import numpy as np
import time
import threading
from .FileReader import *
from datetime import datetime

class AnalyzerClientAsync(Node):

    def __init__(self, topic_name):
        super().__init__(topic_name)
        self.client = self.create_client(AnalyzerServer, 'analyzer_server')
        while not self.client.wait_for_service(timeout_sec=5.0):
            self.get_logger().info('service not available, waiting again...')
        self.request = AnalyzerServer.Request()

    def send_request(self, data: ControllerDataClass):
        #print("send_request")
        #print(data)

        self.request.time = data[0]
        self.request.pitch = data[2]
        self.request.roll = data[3]
        self.request.course = data[4]
        self.request.w_x = data[5]
        self.request.w_y = data[6]
        self.request.w_z = data[7]
        self.request.a_x = data[8]
        self.request.a_y = data[9]
        self.request.a_z = data[10]
        self.request.gps_speed = data[11]
        self.request.gps_track_angle = data[12]
        self.request.gps_satellite_number = data[13]
        self.request.altitude = data[14]
        self.request.latitude = data[15]
        self.request.longitude = data[16]
        self.request.gps_utc_date = data[17]
        self.request.utc_time = data[18]
        self.request.targeting = data[19]
        self.request.temperature = data[20]

        # self.request.time = time
        # self.request.pitch = data.pitch
        # self.request.roll = data.roll
        # self.request.course = data.course
        # self.request.w_x = data.w_x
        # self.request.w_y = data.w_y
        # self.request.w_z = data.w_z
        # self.request.a_x = data.a_x
        # self.request.a_y = data.a_y
        # self.request.a_z = data.a_z
        # self.request.gps_speed = data.gps_speed
        # self.request.gps_track_angle = data.gps_track_angle
        # self.request.gps_satellite_number = data.gps_satellite_number
        # self.request.altitude = data.altitude
        # self.request.latitude = data.latitude
        # self.request.longitude = data.longitude
        # self.request.gps_utc_date = data.gps_utc_date
        # self.request.utc_time = data.utc_time
        # self.request.targeting = data.targeting
        # self.request.temperature = data.temperature

        self.future = self.client.call_async(self.request)


def group_call(a):
    print("Group")
    minimal_client = AnalyzerClientAsync(a)
    minimal_client.send_request()
    minimal_client.self_spin()

# def loop():
#     for i in range(3):
#         a = "kek" + str(i) + "kek"
#         print(a)
#         group_call(a)
#
#     print("ENDLOOP")
#
#
# def main(args=None):
#     rclpy.init(args=args)
#
#     loop()
#
#     while True:
#         pass
#
#     # database_thread = threading.Thread(target=loop)
#     # database_thread.setDaemon(True)
#     # database_thread.start()
#
#     # while rclpy.ok():
#     #     print("a")
#     #     rclpy.spin_once(minimal_client)
#     #     if minimal_client.future.done():
#     #         try:
#     #             response = minimal_client.future.result()
#     #         except Exception as e:
#     #             minimal_client.get_logger().info(
#     #                 'Service call failed %r' % (e,))
#     #         else:
#     #             minimal_client.get_logger().info(
#     #                 'Result of add_three_ints: for %d + %d + %d = %d')
#     #         break
#     #
#     # minimal_client.destroy_node()
#     rclpy.shutdown()
#
#
# if __name__ == '__main__':
#     main()