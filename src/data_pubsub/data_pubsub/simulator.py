import numpy as np
import configparser
import math 
import random
from .FileReader import *
from collections import deque

class Simulator:

    def __init__(self):
        super().__init__()
        self.get_config()


    def get_config(self):
        config = configparser.ConfigParser()
        config.read("config.ini")
        self.simulator_mode = int(config['SimulatorConfig']['simulator_mode'])

        self.pitch_min = int(config['SimulatorDataConfig']['pitch_min'])
        self.pitch_max = int(config['SimulatorDataConfig']['pitch_max'])
        self.roll_min = int(config['SimulatorDataConfig']['roll_min'])
        self.roll_max = int(config['SimulatorDataConfig']['roll_max'])
        self.course_min = int(config['SimulatorDataConfig']['course_min'])
        self.course_max = int(config['SimulatorDataConfig']['course_max'])
        self.w_x_min = int(config['SimulatorDataConfig']['w_x_min'])
        self.w_x_max = int(config['SimulatorDataConfig']['w_x_max'])
        self.w_y_min = int(config['SimulatorDataConfig']['w_y_min'])
        self.w_y_max = int(config['SimulatorDataConfig']['w_y_max'])
        self.w_z_min = int(config['SimulatorDataConfig']['w_z_min'])
        self.w_z_max = int(config['SimulatorDataConfig']['w_z_max'])
        self.a_x_min = int(config['SimulatorDataConfig']['a_x_min'])
        self.a_x_max = int(config['SimulatorDataConfig']['a_x_max'])
        self.a_y_min = int(config['SimulatorDataConfig']['a_y_min'])
        self.a_y_max = int(config['SimulatorDataConfig']['a_y_max'])
        self.a_z_min = int(config['SimulatorDataConfig']['a_z_min'])
        self.a_z_max = int(config['SimulatorDataConfig']['a_z_max'])
        self.gps_speed_min = int(config['SimulatorDataConfig']['gps_speed_min'])
        self.gps_speed_max = int(config['SimulatorDataConfig']['gps_speed_max'])
        self.gps_track_angle_min = int(config['SimulatorDataConfig']['gps_track_angle_min'])
        self.gps_track_angle_max = int(config['SimulatorDataConfig']['gps_track_angle_max'])
        self.gps_satellite_number_min = int(config['SimulatorDataConfig']['gps_satellite_number_min'])
        self.gps_satellite_number_max = int(config['SimulatorDataConfig']['gps_satellite_number_max'])
        self.altitude_min = int(config['SimulatorDataConfig']['altitude_min'])
        self.altitude_max = int(config['SimulatorDataConfig']['altitude_max'])
        self.latitude_min = int(config['SimulatorDataConfig']['latitude_min'])
        self.latitude_max = int(config['SimulatorDataConfig']['latitude_max'])
        self.longitude_min = int(config['SimulatorDataConfig']['longitude_min'])
        self.longitude_max = int(config['SimulatorDataConfig']['longitude_max'])
        self.gps_utc_date_min = int(config['SimulatorDataConfig']['gps_utc_date_min'])
        self.gps_utc_date_max = int(config['SimulatorDataConfig']['gps_utc_date_max'])
        self.utc_time_min = int(config['SimulatorDataConfig']['utc_time_min'])
        self.utc_time_max = int(config['SimulatorDataConfig']['utc_time_max'])
        self.targeting_min = int(config['SimulatorDataConfig']['targeting_min'])
        self.targeting_max = int(config['SimulatorDataConfig']['targeting_max'])
        self.temperature_min = int(config['SimulatorDataConfig']['temperature_min'])
        self.temperature_max = int(config['SimulatorDataConfig']['temperature_max'])

    def simulate_new_value(self, deque):
        data_list = deque.copy()

        pitch_list = []
        roll_list = []
        course_list = []
        w_x_list = []
        w_y_list = []
        w_z_list = []
        a_x_list = []
        a_y_list = []
        a_z_list = []
        gps_speed_list = []
        gps_track_angle_list = []
        gps_satellite_number_list = []
        altitude_list = []
        latitude_list = []
        longitude_list = []
        gps_utc_date_list = []
        utc_time_list = []
        targeting_list = []
        temperature_list = []

        for data in reversed(data_list):
            pitch_list.append(data.pitch)
            roll_list.append(data.roll)
            course_list.append(data.course)
            w_x_list.append(data.w_x)
            w_y_list.append(data.w_y)
            w_z_list.append(data.w_z)
            a_x_list.append(data.a_x)
            a_y_list.append(data.a_y)
            a_z_list.append(data.a_z)
            gps_speed_list.append(data.gps_speed)
            gps_track_angle_list.append(data.gps_track_angle)
            gps_satellite_number_list.append(data.gps_satellite_number)
            altitude_list.append(data.altitude)
            latitude_list.append(data.latitude)
            longitude_list.append(data.longitude)
            gps_utc_date_list.append(data.gps_utc_date)
            utc_time_list.append(data.utc_time)
            targeting_list.append(data.targeting)
            temperature_list.append(data.temperature)

        new_value = ControllerDataClass('0')
        new_value.pitch = self.new_value(pitch_list, False, "pitch")
        new_value.roll = self.new_value(roll_list, False, "roll")
        new_value.course = self.new_value(course_list, False, "course")
        new_value.w_x = self.new_value(w_x_list, False, "w_x")
        new_value.w_y = self.new_value(w_y_list, False, "w_y")
        new_value.w_z = self.new_value(w_z_list, False, "w_z")
        new_value.a_x = self.new_value(a_x_list, False, "a_x")
        new_value.a_y = self.new_value(a_y_list, False, "a_y")
        new_value.a_z = self.new_value(a_z_list, False, "a_z")
        new_value.gps_speed = self.new_value(gps_speed_list, False, "gps_speed")
        new_value.gps_track_angle = self.new_value(gps_track_angle_list, False, "gps_track_angle")
        new_value.gps_satellite_number = self.new_value(gps_satellite_number_list, True, "gps_satellite_number")
        new_value.altitude = self.new_value(altitude_list, False, "altitude")
        new_value.latitude = self.new_value(latitude_list, False, "latitude")
        new_value.longitude = self.new_value(longitude_list, False, "longitude")
        new_value.gps_utc_date = self.new_value(gps_utc_date_list, False, "gps_utc_date")
        new_value.utc_time = self.new_value(utc_time_list, False, "utc_time")
        new_value.targeting = self.new_value(targeting_list, True, "targeting")
        new_value.temperature = self.new_value(temperature_list, True, "temperature")

        print("NEW VALUE TEM", new_value.temperature)

        return new_value

    def average(self, lst):
        return sum(lst) / len(lst)

    def new_value(self, list, is_int, id):

        if id == "pitch":
            return self.simulate_mode_func(list, self.pitch_min, self.pitch_max, is_int)
        elif id == "roll":
            return self.simulate_mode_func(list, self.roll_min, self.roll_max, is_int)
        elif id == "course":
            return self.simulate_mode_func(list, self.course_min, self.course_max, is_int)
        elif id == "w_x":
            return self.simulate_mode_func(list, self.w_x_min, self.w_x_max, is_int)
        elif id == "w_y":
            return self.simulate_mode_func(list, self.w_y_min, self.w_y_max, is_int)
        elif id == "w_z":
            return self.simulate_mode_func(list, self.w_z_min, self.w_z_max, is_int)
        elif id == "a_x":
            return self.simulate_mode_func(list, self.a_x_min, self.a_x_max, is_int)
        elif id == "a_y":
            return self.simulate_mode_func(list, self.a_y_min, self.a_y_max, is_int)
        elif id == "a_z":
            return self.simulate_mode_func(list, self.a_z_min, self.a_z_max, is_int)
        elif id == "gps_speed":
            return self.simulate_mode_func(list, self.gps_speed_min, self.gps_speed_max, is_int)
        elif id == "gps_track_angle":
            return self.simulate_mode_func(list, self.gps_track_angle_min, self.gps_track_angle_max, is_int)
        elif id == "gps_satellite_number":
            return self.simulate_mode_func(list, self.gps_satellite_number_min, self.gps_satellite_number_max, is_int)
        elif id == "altitude":
            return self.simulate_mode_func(list, self.altitude_min, self.altitude_max, is_int)
        elif id == "latitude":
            return self.simulate_mode_func(list, self.latitude_min, self.latitude_max, is_int)
        elif id == "longitude":
            return self.simulate_mode_func(list, self.longitude_min, self.longitude_max, is_int)
        elif id == "gps_utc_date":
            return self.simulate_mode_func(list, self.gps_utc_date_min, self.gps_utc_date_max, is_int)
        elif id == "utc_time":
            return self.simulate_mode_func(list, self.utc_time_min, self.utc_time_max, is_int)
        elif id == "targeting":
            return self.simulate_mode_func(list, self.targeting_min, self.targeting_max, is_int)
        elif id == "temperature":
            return self.simulate_mode_func(list, self.temperature_min, self.temperature_max, is_int)

        # if is_int:
        #     random_value = random.randint(0, 100)
        #     avg = int(avg) + random_value
        #     print("RANDOM", random_value)
        # else:
        #     random_value = random.randint(0, 100)
        #     avg = avg + random_value
        #     print("RANDOM", random_value)

        print("REAL", list[0])
        return avg

    def simulate_mode_func(self, current, bottom, top, is_int):
        new_value = 0
        if self.simulator_mode == 0:
            new_value = self.average(current)
        if self.simulator_mode == 1:
            if is_int:
                new_value = random.randint(bottom, top)
            else:
                new_value = random.uniform(bottom, top)
        return new_value





