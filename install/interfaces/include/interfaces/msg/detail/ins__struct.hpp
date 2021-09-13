// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/Ins.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__INS__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__INS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interfaces__msg__Ins __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__Ins __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Ins_
{
  using Type = Ins_<ContainerAllocator>;

  explicit Ins_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->pitch = 0.0;
      this->roll = 0.0;
      this->course = 0.0;
      this->w_x = 0.0;
      this->w_y = 0.0;
      this->w_z = 0.0;
      this->a_x = 0.0;
      this->a_y = 0.0;
      this->a_z = 0.0;
      this->gps_speed = 0.0;
      this->gps_track_angle = 0.0;
      this->gps_satellite_number = 0.0;
      this->altitude = 0.0;
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->gps_utc_date = 0.0;
      this->utc_time = 0.0;
      this->targeting = 0;
      this->temperature = 0;
    }
  }

  explicit Ins_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
      this->pitch = 0.0;
      this->roll = 0.0;
      this->course = 0.0;
      this->w_x = 0.0;
      this->w_y = 0.0;
      this->w_z = 0.0;
      this->a_x = 0.0;
      this->a_y = 0.0;
      this->a_z = 0.0;
      this->gps_speed = 0.0;
      this->gps_track_angle = 0.0;
      this->gps_satellite_number = 0.0;
      this->altitude = 0.0;
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->gps_utc_date = 0.0;
      this->utc_time = 0.0;
      this->targeting = 0;
      this->temperature = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _status_type =
    unsigned char;
  _status_type status;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _roll_type =
    double;
  _roll_type roll;
  using _course_type =
    double;
  _course_type course;
  using _w_x_type =
    double;
  _w_x_type w_x;
  using _w_y_type =
    double;
  _w_y_type w_y;
  using _w_z_type =
    double;
  _w_z_type w_z;
  using _a_x_type =
    double;
  _a_x_type a_x;
  using _a_y_type =
    double;
  _a_y_type a_y;
  using _a_z_type =
    double;
  _a_z_type a_z;
  using _gps_speed_type =
    double;
  _gps_speed_type gps_speed;
  using _gps_track_angle_type =
    double;
  _gps_track_angle_type gps_track_angle;
  using _gps_satellite_number_type =
    double;
  _gps_satellite_number_type gps_satellite_number;
  using _altitude_type =
    double;
  _altitude_type altitude;
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _longitude_type =
    double;
  _longitude_type longitude;
  using _gps_utc_date_type =
    double;
  _gps_utc_date_type gps_utc_date;
  using _utc_time_type =
    double;
  _utc_time_type utc_time;
  using _targeting_type =
    uint16_t;
  _targeting_type targeting;
  using _temperature_type =
    uint16_t;
  _temperature_type temperature;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__status(
    const unsigned char & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__course(
    const double & _arg)
  {
    this->course = _arg;
    return *this;
  }
  Type & set__w_x(
    const double & _arg)
  {
    this->w_x = _arg;
    return *this;
  }
  Type & set__w_y(
    const double & _arg)
  {
    this->w_y = _arg;
    return *this;
  }
  Type & set__w_z(
    const double & _arg)
  {
    this->w_z = _arg;
    return *this;
  }
  Type & set__a_x(
    const double & _arg)
  {
    this->a_x = _arg;
    return *this;
  }
  Type & set__a_y(
    const double & _arg)
  {
    this->a_y = _arg;
    return *this;
  }
  Type & set__a_z(
    const double & _arg)
  {
    this->a_z = _arg;
    return *this;
  }
  Type & set__gps_speed(
    const double & _arg)
  {
    this->gps_speed = _arg;
    return *this;
  }
  Type & set__gps_track_angle(
    const double & _arg)
  {
    this->gps_track_angle = _arg;
    return *this;
  }
  Type & set__gps_satellite_number(
    const double & _arg)
  {
    this->gps_satellite_number = _arg;
    return *this;
  }
  Type & set__altitude(
    const double & _arg)
  {
    this->altitude = _arg;
    return *this;
  }
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__gps_utc_date(
    const double & _arg)
  {
    this->gps_utc_date = _arg;
    return *this;
  }
  Type & set__utc_time(
    const double & _arg)
  {
    this->utc_time = _arg;
    return *this;
  }
  Type & set__targeting(
    const uint16_t & _arg)
  {
    this->targeting = _arg;
    return *this;
  }
  Type & set__temperature(
    const uint16_t & _arg)
  {
    this->temperature = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::Ins_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::Ins_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::Ins_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::Ins_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Ins_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Ins_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Ins_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Ins_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::Ins_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::Ins_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__Ins
    std::shared_ptr<interfaces::msg::Ins_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__Ins
    std::shared_ptr<interfaces::msg::Ins_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Ins_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->course != other.course) {
      return false;
    }
    if (this->w_x != other.w_x) {
      return false;
    }
    if (this->w_y != other.w_y) {
      return false;
    }
    if (this->w_z != other.w_z) {
      return false;
    }
    if (this->a_x != other.a_x) {
      return false;
    }
    if (this->a_y != other.a_y) {
      return false;
    }
    if (this->a_z != other.a_z) {
      return false;
    }
    if (this->gps_speed != other.gps_speed) {
      return false;
    }
    if (this->gps_track_angle != other.gps_track_angle) {
      return false;
    }
    if (this->gps_satellite_number != other.gps_satellite_number) {
      return false;
    }
    if (this->altitude != other.altitude) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->gps_utc_date != other.gps_utc_date) {
      return false;
    }
    if (this->utc_time != other.utc_time) {
      return false;
    }
    if (this->targeting != other.targeting) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    return true;
  }
  bool operator!=(const Ins_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Ins_

// alias to use template instance with default allocator
using Ins =
  interfaces::msg::Ins_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__INS__STRUCT_HPP_
