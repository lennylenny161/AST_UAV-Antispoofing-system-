import rclpy
from rclpy.node import Node
import sys
import threading

from interfaces.msg import SpoofingControl
from interfaces.msg import Ins
from PyQt5 import QtCore, QtGui, QtWidgets
from .RosAttackUI import *

class ExampleApp(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.button_state = True
        self.setupUi(self)
        self.pushButton.clicked.connect(self.start_state_change)

        threading.Thread(target=self.create_exec).start()

    def create_exec(self):
        rclpy.init(args=None)

        self.state_publisher = StatePublisher()

        executor = rclpy.executors.MultiThreadedExecutor()

        executor.add_node(self.state_publisher)

        executor_thread = threading.Thread(target=executor.spin, daemon=True)
        executor_thread.start()
        rate = self.state_publisher.create_rate(1)  # Потыкать
        try:
            while rclpy.ok():
                rate.sleep()
        except KeyboardInterrupt:
            pass
        rclpy.shutdown()
        executor_thread.join()

    def start_state_change(self):

        self.state_publisher.callback(self.button_state)

        self.button_state = not self.button_state
        if not self.button_state:
            self.pushButton.setText("Прекратить атаку")
        else:
            self.pushButton.setText("Запустить атаку")

class StatePublisher(Node):

    spoof_cntrl_state_off = bytes('0', 'utf-8')
    spoof_cntrl_state_on = bytes('1', 'utf-8')

    def __init__(self):
        super().__init__('spoof_state_publisher')
        self.publisher_ = self.create_publisher(SpoofingControl, 'spoofing_control_topic', 10)

    def callback(self, spoof_state):
        msg = SpoofingControl()

        if spoof_state == False:
            msg.spoof_cntrl_state = self.spoof_cntrl_state_off
        else:
            msg.spoof_cntrl_state = self.spoof_cntrl_state_on
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing control byte: "%a"' % (msg.spoof_cntrl_state))


def main(args=None):
    app = QtWidgets.QApplication(sys.argv)
    window = ExampleApp()
    window.show()

    app.exec_()


if __name__ == '__main__':
    main()
