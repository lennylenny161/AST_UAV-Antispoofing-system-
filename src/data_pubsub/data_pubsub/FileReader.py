import numpy as np

class ControllerDataClass:

    def __init__(self,
                 status = bytes('0', 'utf-8'),
                 pitch: np.float64 = 0.0,
                 roll: np.float64 = 0.0,
                 course: np.float64 = 0.0,
                 w_x: np.float64 = 0.0,
                 w_y: np.float64 = 0.0,
                 w_z: np.float64 = 0.0,
                 a_x: np.float64 = 0.0,
                 a_y: np.float64 = 0.0,
                 a_z: np.float64 = 0.0,
                 gps_speed: np.float64 = 0.0,
                 gps_track_angle: np.float64 = 0.0,
                 gps_satellite_number: np.float64 = 0.0,
                 altitude: np.float64 = 0.0,
                 latitude: np.float64 = 0.0,
                 longitude: np.float64 = 0.0,
                 gps_utc_date: np.float64 = 0.0,
                 utc_time: np.float64 = 0.0,
                 targeting: int = 0,
                 temperature: int = 0):
        self.status = bytes(str(status), 'utf-8')
        self.pitch = np.float64(pitch)
        self.roll = np.float64(roll)
        self.course = np.float64(course)
        self.w_x = np.float64(w_x)
        self.w_y = np.float64(w_y)
        self.w_z = np.float64(w_z)
        self.a_x = np.float64(a_x)
        self.a_y = np.float64(a_y)
        self.a_z = np.float64(a_z)
        self.gps_speed = np.float64(gps_speed)
        self.gps_track_angle = np.float64(gps_track_angle)
        self.gps_satellite_number = np.float64(gps_satellite_number)
        self.altitude = np.float64(altitude)
        self.latitude = np.float64(latitude)
        self.longitude = np.float64(longitude)
        self.gps_utc_date = np.float64(gps_utc_date)
        self.utc_time = np.float64(utc_time)
        self.targeting = int(targeting)
        self.temperature = int(temperature)


class FileReader:

    def __init__(self, file_name):
        self.file_name = file_name

    def parse_raw_data(self, event):
        raw_data = event
        raw_data = raw_data[1:-2].split(', ')
        data = ControllerDataClass(raw_data[0],
                                   raw_data[1],
                                   raw_data[2],
                                   raw_data[3],
                                   raw_data[4],
                                   raw_data[5],
                                   raw_data[6],
                                   raw_data[7],
                                   raw_data[8],
                                   raw_data[9],
                                   raw_data[10],
                                   raw_data[11],
                                   raw_data[12],
                                   raw_data[13],
                                   raw_data[14],
                                   raw_data[15],
                                   raw_data[16],
                                   raw_data[17],
                                   raw_data[18],
                                   raw_data[19])
        return data

    def read_data_from_file(self):
        with open(self.file_name, 'r') as reader:
            events = []
            for event in reader:
                event_data = self.parse_raw_data(event)
                events.append(event_data)
            return events

