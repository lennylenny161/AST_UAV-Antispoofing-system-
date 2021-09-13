// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/Ins.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__INS__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__INS__BUILDER_HPP_

#include "interfaces/msg/detail/ins__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_Ins_temperature
{
public:
  explicit Init_Ins_temperature(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::Ins temperature(::interfaces::msg::Ins::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_targeting
{
public:
  explicit Init_Ins_targeting(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_temperature targeting(::interfaces::msg::Ins::_targeting_type arg)
  {
    msg_.targeting = std::move(arg);
    return Init_Ins_temperature(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_utc_time
{
public:
  explicit Init_Ins_utc_time(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_targeting utc_time(::interfaces::msg::Ins::_utc_time_type arg)
  {
    msg_.utc_time = std::move(arg);
    return Init_Ins_targeting(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_gps_utc_date
{
public:
  explicit Init_Ins_gps_utc_date(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_utc_time gps_utc_date(::interfaces::msg::Ins::_gps_utc_date_type arg)
  {
    msg_.gps_utc_date = std::move(arg);
    return Init_Ins_utc_time(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_longitude
{
public:
  explicit Init_Ins_longitude(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_gps_utc_date longitude(::interfaces::msg::Ins::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_Ins_gps_utc_date(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_latitude
{
public:
  explicit Init_Ins_latitude(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_longitude latitude(::interfaces::msg::Ins::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_Ins_longitude(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_altitude
{
public:
  explicit Init_Ins_altitude(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_latitude altitude(::interfaces::msg::Ins::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_Ins_latitude(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_gps_satellite_number
{
public:
  explicit Init_Ins_gps_satellite_number(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_altitude gps_satellite_number(::interfaces::msg::Ins::_gps_satellite_number_type arg)
  {
    msg_.gps_satellite_number = std::move(arg);
    return Init_Ins_altitude(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_gps_track_angle
{
public:
  explicit Init_Ins_gps_track_angle(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_gps_satellite_number gps_track_angle(::interfaces::msg::Ins::_gps_track_angle_type arg)
  {
    msg_.gps_track_angle = std::move(arg);
    return Init_Ins_gps_satellite_number(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_gps_speed
{
public:
  explicit Init_Ins_gps_speed(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_gps_track_angle gps_speed(::interfaces::msg::Ins::_gps_speed_type arg)
  {
    msg_.gps_speed = std::move(arg);
    return Init_Ins_gps_track_angle(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_a_z
{
public:
  explicit Init_Ins_a_z(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_gps_speed a_z(::interfaces::msg::Ins::_a_z_type arg)
  {
    msg_.a_z = std::move(arg);
    return Init_Ins_gps_speed(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_a_y
{
public:
  explicit Init_Ins_a_y(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_a_z a_y(::interfaces::msg::Ins::_a_y_type arg)
  {
    msg_.a_y = std::move(arg);
    return Init_Ins_a_z(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_a_x
{
public:
  explicit Init_Ins_a_x(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_a_y a_x(::interfaces::msg::Ins::_a_x_type arg)
  {
    msg_.a_x = std::move(arg);
    return Init_Ins_a_y(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_w_z
{
public:
  explicit Init_Ins_w_z(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_a_x w_z(::interfaces::msg::Ins::_w_z_type arg)
  {
    msg_.w_z = std::move(arg);
    return Init_Ins_a_x(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_w_y
{
public:
  explicit Init_Ins_w_y(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_w_z w_y(::interfaces::msg::Ins::_w_y_type arg)
  {
    msg_.w_y = std::move(arg);
    return Init_Ins_w_z(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_w_x
{
public:
  explicit Init_Ins_w_x(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_w_y w_x(::interfaces::msg::Ins::_w_x_type arg)
  {
    msg_.w_x = std::move(arg);
    return Init_Ins_w_y(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_course
{
public:
  explicit Init_Ins_course(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_w_x course(::interfaces::msg::Ins::_course_type arg)
  {
    msg_.course = std::move(arg);
    return Init_Ins_w_x(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_roll
{
public:
  explicit Init_Ins_roll(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_course roll(::interfaces::msg::Ins::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_Ins_course(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_pitch
{
public:
  explicit Init_Ins_pitch(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_roll pitch(::interfaces::msg::Ins::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Ins_roll(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_status
{
public:
  explicit Init_Ins_status(::interfaces::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_pitch status(::interfaces::msg::Ins::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Ins_pitch(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

class Init_Ins_header
{
public:
  Init_Ins_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Ins_status header(::interfaces::msg::Ins::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Ins_status(msg_);
  }

private:
  ::interfaces::msg::Ins msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::Ins>()
{
  return interfaces::msg::builder::Init_Ins_header();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__INS__BUILDER_HPP_
