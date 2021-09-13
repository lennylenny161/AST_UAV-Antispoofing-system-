import rclpy
from rclpy.node import Node

from interfaces.msg import SpoofingControl

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.state_switch = False
        self.publisher_ = self.create_publisher(SpoofingControl, 'spoofing_control_topic2', 10)
        timer_period = 0.3  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = SpoofingControl()
        
        spoof_cntrl_state_off = bytes('0', 'utf-8')
        spoof_cntrl_state_on = bytes('1', 'utf-8')
        if self.state_switch == False:
            self.state_switch = True
            msg.spoof_cntrl_state = spoof_cntrl_state_off
        else:
            self.state_switch = False
            msg.spoof_cntrl_state = spoof_cntrl_state_on
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing control byte: "%a"' % (msg.spoof_cntrl_state))


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
