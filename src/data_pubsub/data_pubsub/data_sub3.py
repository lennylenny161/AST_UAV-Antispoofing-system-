import rclpy
from rclpy.node import Node

from interfaces.msg import Ins

class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('fake_class')
        self.subscription = self.create_subscription(
            Ins,
            'fake_ins_data',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        print(msg)
        #self.get_logger().info('I heard: "%s" "%s"' % (msg.nav_state.decode('utf-8'), msg.module_state.decode('utf-8')))


def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()

    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()