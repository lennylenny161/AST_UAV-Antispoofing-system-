import sqlite3
from .FileReader import *
import numpy as np

class DatabaseWorker:

    @staticmethod
    def create_connection():
        conn = None
        try:
            conn = sqlite3.connect('data_database')
        except Error as e:
            print("ERROR___", e)

        return conn


    @staticmethod
    def write_data(connect, data: ControllerDataClass, time, beFake):

        cursor = connect.cursor()
        status = data.status.decode('utf-8')
        task = (time,
                status,
                data.pitch,
                data.roll,
                data.course,
                data.w_x,
                data.w_y,
                data.w_z,
                data.a_x,
                data.a_y,
                data.a_z,
                data.gps_speed,
                data.gps_track_angle,
                data.gps_satellite_number,
                data.altitude,
                data.latitude,
                data.longitude,
                data.gps_utc_date,
                data.utc_time,
                data.targeting,
                data.temperature,
                beFake)

        sql = ''' INSERT INTO msg_list(msg_time,status,pitch,roll,course,w_x,w_y,w_z,a_x,a_y,a_z,gps_speed,gps_track_angle,gps_satellite_number,altitude,latitude,longitude,gps_utc_date,utc_time,targeting,temperature,beFake)
                      VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?) '''

        cursor.execute(sql, task)
        connect.commit()

        return cursor.lastrowid
