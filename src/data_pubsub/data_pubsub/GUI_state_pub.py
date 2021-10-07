import rclpy
from rclpy.node import Node
import sys
import threading

from interfaces.msg import SpoofingControl
from interfaces.msg import Ins
from interfaces.msg import AnalyzerCallback
from PyQt5 import QtCore, QtGui, QtWidgets
from .RosAttackUI import *


class Monitor(QtCore.QObject):

    updateText = QtCore.pyqtSignal(str)

    def update_list(self, txt):
        t_monitor = Thread(self.monitor_vector, args=(txt,), kwargs={}, parent=self)
        t_monitor.daemon = True
        t_monitor.start()

    def monitor_vector(self, txt):
        self.updateText.emit(txt)


class Thread(QtCore.QThread):

    def __init__(self, fn, args, kwargs, parent=None):
        super(Thread, self).__init__(parent)
        self._fn = fn
        self._args = args
        self._kwargs = kwargs

    def run(self):
        self._fn(*self._args, **self._kwargs)

class ExampleApp(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.button_state = True
        self.setupUi(self)
        self.pushButton.clicked.connect(self.start_state_change)

        self.monitor = Monitor()
        self.monitor.updateText.connect(self.set_text)

        threading.Thread(target=self.create_exec).start()

    def create_exec(self):
        rclpy.init(args=None)

        self.state_publisher = StatePublisher()
        self.simulator_subscriber = SimulatorSubscriber(self.monitor)

        executor = rclpy.executors.MultiThreadedExecutor()

        executor.add_node(self.state_publisher)
        executor.add_node(self.simulator_subscriber)

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

    def set_text(self, text):
        self.textBrowser.insertPlainText(text)

class SimulatorSubscriber(Node):

    def __init__(self, monitor):
        super().__init__('simulator_subscriber')

        callback_lambda = lambda x: self.listener_callback(x, monitor)
        self.subscription = self.create_subscription(
            AnalyzerCallback,
            'simulator_topic',
            callback_lambda,
            10)
        self.subscription

    def listener_callback(self, msg, monitor):
        print("CALLBACK SUBSCRIBER")
        print(msg)
        text = str(msg.check_result) + " " + str(msg.error_code) + " " + msg.error_description + '\n'
        print(text)
        # app.set_text(text)
        monitor.update_list(text)
        #threading.Thread(target=textField.setText, args=(text,), daemon=True).start()

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
