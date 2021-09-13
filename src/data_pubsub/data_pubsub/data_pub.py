import rclpy
from rclpy.node import Node
from interfaces.msg import Ins
from .FileReader import *

class DataPublisher(Node):

    def __init__(self, data):
        super().__init__('data_publisher')
        self.publisher_ = self.create_publisher(Ins, 'data_topic', 10)
        timer_period = 2  # seconds
        self.data = data
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = Ins()
        for event in self.data:
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.status = event.status
            msg.pitch = event.pitch
            msg.roll = event.roll
            msg.course = event.course
            msg.w_x = event.w_x
            msg.w_y = event.w_y
            msg.w_z = event.w_z
            msg.a_x = event.a_x
            msg.a_y = event.a_y
            msg.a_z = event.a_z
            msg.gps_speed = event.gps_speed
            msg.gps_track_angle = event.gps_track_angle
            msg.gps_satellite_number = event.gps_satellite_number
            msg.altitude = event.altitude
            msg.latitude = event.latitude
            msg.longitude = event.longitude
            msg.gps_utc_date = event.gps_utc_date
            msg.utc_time = event.utc_time
            msg.targeting = event.targeting
            msg.temperature = event.temperature

            self.publisher_.publish(msg)
            self.get_logger().info('Publishing: status "%a" '
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


def main(args=None):
    rclpy.init(args=args)
    file_reader = FileReader('fileData.txt')
    file_data = file_reader.read_data_from_file()
    minimal_publisher = DataPublisher(file_data)

    rclpy.spin(minimal_publisher)

    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
