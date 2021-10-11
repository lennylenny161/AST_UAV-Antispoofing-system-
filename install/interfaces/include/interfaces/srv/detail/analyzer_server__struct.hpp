// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:srv/AnalyzerServer.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__ANALYZER_SERVER__STRUCT_HPP_
#define INTERFACES__SRV__DETAIL__ANALYZER_SERVER__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__AnalyzerServer_Request __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__AnalyzerServer_Request __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AnalyzerServer_Request_
{
  using Type = AnalyzerServer_Request_<ContainerAllocator>;

  explicit AnalyzerServer_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time = 0.0;
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
      this->gps_satellite_number = 0;
      this->altitude = 0.0;
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->gps_utc_date = 0.0;
      this->utc_time = 0.0;
      this->targeting = 0;
      this->temperature = 0;
    }
  }

  explicit AnalyzerServer_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time = 0.0;
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
      this->gps_satellite_number = 0;
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
  using _time_type =
    double;
  _time_type time;
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
    uint16_t;
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
    int16_t;
  _targeting_type targeting;
  using _temperature_type =
    uint16_t;
  _temperature_type temperature;

  // setters for named parameter idiom
  Type & set__time(
    const double & _arg)
  {
    this->time = _arg;
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
    const uint16_t & _arg)
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
    const int16_t & _arg)
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
    interfaces::srv::AnalyzerServer_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::AnalyzerServer_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::AnalyzerServer_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::AnalyzerServer_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::AnalyzerServer_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::AnalyzerServer_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::AnalyzerServer_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::AnalyzerServer_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::AnalyzerServer_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::AnalyzerServer_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__AnalyzerServer_Request
    std::shared_ptr<interfaces::srv::AnalyzerServer_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__AnalyzerServer_Request
    std::shared_ptr<interfaces::srv::AnalyzerServer_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AnalyzerServer_Request_ & other) const
  {
    if (this->time != other.time) {
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
  bool operator!=(const AnalyzerServer_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AnalyzerServer_Request_

// alias to use template instance with default allocator
using AnalyzerServer_Request =
  interfaces::srv::AnalyzerServer_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces


#ifndef _WIN32
# define DEPRECATED__interfaces__srv__AnalyzerServer_Response __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__srv__AnalyzerServer_Response __declspec(deprecated)
#endif

namespace interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AnalyzerServer_Response_
{
  using Type = AnalyzerServer_Response_<ContainerAllocator>;

  explicit AnalyzerServer_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->check_result = false;
      this->error_code = 0ll;
      this->error_description = "";
    }
  }

  explicit AnalyzerServer_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error_description(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->check_result = false;
      this->error_code = 0ll;
      this->error_description = "";
    }
  }

  // field types and members
  using _check_result_type =
    bool;
  _check_result_type check_result;
  using _error_code_type =
    int64_t;
  _error_code_type error_code;
  using _error_description_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _error_description_type error_description;

  // setters for named parameter idiom
  Type & set__check_result(
    const bool & _arg)
  {
    this->check_result = _arg;
    return *this;
  }
  Type & set__error_code(
    const int64_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }
  Type & set__error_description(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->error_description = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::srv::AnalyzerServer_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::srv::AnalyzerServer_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::srv::AnalyzerServer_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::srv::AnalyzerServer_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::AnalyzerServer_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::AnalyzerServer_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::srv::AnalyzerServer_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::srv::AnalyzerServer_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::srv::AnalyzerServer_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::srv::AnalyzerServer_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__srv__AnalyzerServer_Response
    std::shared_ptr<interfaces::srv::AnalyzerServer_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__srv__AnalyzerServer_Response
    std::shared_ptr<interfaces::srv::AnalyzerServer_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AnalyzerServer_Response_ & other) const
  {
    if (this->check_result != other.check_result) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    if (this->error_description != other.error_description) {
      return false;
    }
    return true;
  }
  bool operator!=(const AnalyzerServer_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AnalyzerServer_Response_

// alias to use template instance with default allocator
using AnalyzerServer_Response =
  interfaces::srv::AnalyzerServer_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interfaces

namespace interfaces
{

namespace srv
{

struct AnalyzerServer
{
  using Request = interfaces::srv::AnalyzerServer_Request;
  using Response = interfaces::srv::AnalyzerServer_Response;
};

}  // namespace srv

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__ANALYZER_SERVER__STRUCT_HPP_
