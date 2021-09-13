#std_msgs/Header header

byte status

float64 pitch        # pitching angle, grad
float64 roll         # angle of roll, grad
float64 course       # true course, grad

float64 w_x	     # the angular x velocity, grad/s
float64 w_y      # the angular y velocity, grad/s
float64 w_z       # the angular z velocity, grad/s

float64 a_x 	     # x-axis acceleration ,m/s/s
float64 a_y	     # y-axis acceleration,m/s/s
float64 a_z	     # z-axis acceleration,m/s/s

float64 gps_speed
float64 gps_track_angle
float64 gps_satellite_number
float64 altitude

float64 latitude	# Latitude [degrees]. Positive is north of equator; negative is south.
float64 longitude	# Longitude [degrees]. Positive is east of prime meridian; negative is west.

float64 gps_utc_date
float64 utc_time

uint16 targeting
uint16 temperature

