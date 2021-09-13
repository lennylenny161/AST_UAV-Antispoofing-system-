import numpy as np
import configparser
from .FileReader import *
from collections import deque

class Simulator:

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
        new_value.pitch = self.new_value(pitch_list, False)
        new_value.roll = self.new_value(roll_list, False)
        new_value.course = self.new_value(course_list, False)
        new_value.w_x = self.new_value(w_x_list, False)
        new_value.w_y = self.new_value(w_y_list, False)
        new_value.w_z = self.new_value(w_z_list, False)
        new_value.a_x = self.new_value(a_x_list, False)
        new_value.a_y = self.new_value(a_y_list, False)
        new_value.a_z = self.new_value(a_z_list, False)
        new_value.gps_speed = self.new_value(gps_speed_list, False)
        new_value.gps_track_angle = self.new_value(gps_track_angle_list, False)
        new_value.gps_satellite_number = self.new_value(gps_satellite_number_list, False)
        new_value.altitude = self.new_value(altitude_list, False)
        new_value.latitude = self.new_value(latitude_list, False)
        new_value.longitude = self.new_value(longitude_list, False)
        new_value.gps_utc_date = self.new_value(gps_utc_date_list, False)
        new_value.utc_time = self.new_value(utc_time_list, False)
        new_value.targeting = self.new_value(targeting_list, True)
        new_value.temperature = self.new_value(temperature_list, True)

        return new_value

    def average(self, lst):
        return sum(lst) / len(lst)

    def new_value(self, list, is_int):
        #last_value = list[-1]
        avg = self.average(list)
        if is_int:
            avg = int(avg)

        return avg
        #sign = True
        #if list[-2] > list[-1]:
         #   sign = False

        #f sign == True:
