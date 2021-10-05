import logging


class Loger:
    @staticmethod
    def set_type(type):
        if type == "db":
            logging.basicConfig(filename='database.log', level=logging.INFO, filemode='a', format='%(asctime)s - %(levelname)s - %(message)s', datefmt='%d-%b-%y %H:%M:%S')
        if type == "sim":
            logging.basicConfig(filename='simulator.log', level=logging.INFO, filemode='a', format='%(asctime)s - %(levelname)s - %(message)s', datefmt='%d-%b-%y %H:%M:%S')
        if type == "anal":
            logging.basicConfig(filename='analyzer.log', level=logging.INFO, filemode='a', format='%(asctime)s - %(levelname)s - %(message)s', datefmt='%d-%b-%y %H:%M:%S')



