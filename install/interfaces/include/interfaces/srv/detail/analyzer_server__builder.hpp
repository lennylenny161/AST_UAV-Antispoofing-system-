// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/AnalyzerServer.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__ANALYZER_SERVER__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__ANALYZER_SERVER__BUILDER_HPP_

#include "interfaces/srv/detail/analyzer_server__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_AnalyzerServer_Request_temperature
{
public:
  explicit Init_AnalyzerServer_Request_temperature(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  ::interfaces::srv::AnalyzerServer_Request temperature(::interfaces::srv::AnalyzerServer_Request::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_targeting
{
public:
  explicit Init_AnalyzerServer_Request_targeting(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_temperature targeting(::interfaces::srv::AnalyzerServer_Request::_targeting_type arg)
  {
    msg_.targeting = std::move(arg);
    return Init_AnalyzerServer_Request_temperature(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_utc_time
{
public:
  explicit Init_AnalyzerServer_Request_utc_time(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_targeting utc_time(::interfaces::srv::AnalyzerServer_Request::_utc_time_type arg)
  {
    msg_.utc_time = std::move(arg);
    return Init_AnalyzerServer_Request_targeting(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_gps_utc_date
{
public:
  explicit Init_AnalyzerServer_Request_gps_utc_date(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_utc_time gps_utc_date(::interfaces::srv::AnalyzerServer_Request::_gps_utc_date_type arg)
  {
    msg_.gps_utc_date = std::move(arg);
    return Init_AnalyzerServer_Request_utc_time(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_longitude
{
public:
  explicit Init_AnalyzerServer_Request_longitude(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_gps_utc_date longitude(::interfaces::srv::AnalyzerServer_Request::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_AnalyzerServer_Request_gps_utc_date(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_latitude
{
public:
  explicit Init_AnalyzerServer_Request_latitude(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_longitude latitude(::interfaces::srv::AnalyzerServer_Request::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_AnalyzerServer_Request_longitude(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_altitude
{
public:
  explicit Init_AnalyzerServer_Request_altitude(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_latitude altitude(::interfaces::srv::AnalyzerServer_Request::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_AnalyzerServer_Request_latitude(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_gps_satellite_number
{
public:
  explicit Init_AnalyzerServer_Request_gps_satellite_number(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_altitude gps_satellite_number(::interfaces::srv::AnalyzerServer_Request::_gps_satellite_number_type arg)
  {
    msg_.gps_satellite_number = std::move(arg);
    return Init_AnalyzerServer_Request_altitude(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_gps_track_angle
{
public:
  explicit Init_AnalyzerServer_Request_gps_track_angle(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_gps_satellite_number gps_track_angle(::interfaces::srv::AnalyzerServer_Request::_gps_track_angle_type arg)
  {
    msg_.gps_track_angle = std::move(arg);
    return Init_AnalyzerServer_Request_gps_satellite_number(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_gps_speed
{
public:
  explicit Init_AnalyzerServer_Request_gps_speed(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_gps_track_angle gps_speed(::interfaces::srv::AnalyzerServer_Request::_gps_speed_type arg)
  {
    msg_.gps_speed = std::move(arg);
    return Init_AnalyzerServer_Request_gps_track_angle(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_a_z
{
public:
  explicit Init_AnalyzerServer_Request_a_z(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_gps_speed a_z(::interfaces::srv::AnalyzerServer_Request::_a_z_type arg)
  {
    msg_.a_z = std::move(arg);
    return Init_AnalyzerServer_Request_gps_speed(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_a_y
{
public:
  explicit Init_AnalyzerServer_Request_a_y(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_a_z a_y(::interfaces::srv::AnalyzerServer_Request::_a_y_type arg)
  {
    msg_.a_y = std::move(arg);
    return Init_AnalyzerServer_Request_a_z(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_a_x
{
public:
  explicit Init_AnalyzerServer_Request_a_x(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_a_y a_x(::interfaces::srv::AnalyzerServer_Request::_a_x_type arg)
  {
    msg_.a_x = std::move(arg);
    return Init_AnalyzerServer_Request_a_y(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_w_z
{
public:
  explicit Init_AnalyzerServer_Request_w_z(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_a_x w_z(::interfaces::srv::AnalyzerServer_Request::_w_z_type arg)
  {
    msg_.w_z = std::move(arg);
    return Init_AnalyzerServer_Request_a_x(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_w_y
{
public:
  explicit Init_AnalyzerServer_Request_w_y(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_w_z w_y(::interfaces::srv::AnalyzerServer_Request::_w_y_type arg)
  {
    msg_.w_y = std::move(arg);
    return Init_AnalyzerServer_Request_w_z(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_w_x
{
public:
  explicit Init_AnalyzerServer_Request_w_x(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_w_y w_x(::interfaces::srv::AnalyzerServer_Request::_w_x_type arg)
  {
    msg_.w_x = std::move(arg);
    return Init_AnalyzerServer_Request_w_y(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_course
{
public:
  explicit Init_AnalyzerServer_Request_course(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_w_x course(::interfaces::srv::AnalyzerServer_Request::_course_type arg)
  {
    msg_.course = std::move(arg);
    return Init_AnalyzerServer_Request_w_x(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_roll
{
public:
  explicit Init_AnalyzerServer_Request_roll(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_course roll(::interfaces::srv::AnalyzerServer_Request::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_AnalyzerServer_Request_course(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_pitch
{
public:
  explicit Init_AnalyzerServer_Request_pitch(::interfaces::srv::AnalyzerServer_Request & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Request_roll pitch(::interfaces::srv::AnalyzerServer_Request::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_AnalyzerServer_Request_roll(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

class Init_AnalyzerServer_Request_time
{
public:
  Init_AnalyzerServer_Request_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AnalyzerServer_Request_pitch time(::interfaces::srv::AnalyzerServer_Request::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_AnalyzerServer_Request_pitch(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::AnalyzerServer_Request>()
{
  return interfaces::srv::builder::Init_AnalyzerServer_Request_time();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_AnalyzerServer_Response_error_description
{
public:
  explicit Init_AnalyzerServer_Response_error_description(::interfaces::srv::AnalyzerServer_Response & msg)
  : msg_(msg)
  {}
  ::interfaces::srv::AnalyzerServer_Response error_description(::interfaces::srv::AnalyzerServer_Response::_error_description_type arg)
  {
    msg_.error_description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Response msg_;
};

class Init_AnalyzerServer_Response_error_code
{
public:
  explicit Init_AnalyzerServer_Response_error_code(::interfaces::srv::AnalyzerServer_Response & msg)
  : msg_(msg)
  {}
  Init_AnalyzerServer_Response_error_description error_code(::interfaces::srv::AnalyzerServer_Response::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_AnalyzerServer_Response_error_description(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Response msg_;
};

class Init_AnalyzerServer_Response_check_result
{
public:
  Init_AnalyzerServer_Response_check_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AnalyzerServer_Response_error_code check_result(::interfaces::srv::AnalyzerServer_Response::_check_result_type arg)
  {
    msg_.check_result = std::move(arg);
    return Init_AnalyzerServer_Response_error_code(msg_);
  }

private:
  ::interfaces::srv::AnalyzerServer_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::AnalyzerServer_Response>()
{
  return interfaces::srv::builder::Init_AnalyzerServer_Response_check_result();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__ANALYZER_SERVER__BUILDER_HPP_
