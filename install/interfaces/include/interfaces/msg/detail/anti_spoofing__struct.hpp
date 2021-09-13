// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/AntiSpoofing.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ANTI_SPOOFING__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__ANTI_SPOOFING__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__AntiSpoofing __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__AntiSpoofing __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AntiSpoofing_
{
  using Type = AntiSpoofing_<ContainerAllocator>;

  explicit AntiSpoofing_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0.0f;
      this->b = 0.0f;
      this->c = 0.0f;
      this->nav_state = 0;
      this->module_state = 0;
    }
  }

  explicit AntiSpoofing_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0.0f;
      this->b = 0.0f;
      this->c = 0.0f;
      this->nav_state = 0;
      this->module_state = 0;
    }
  }

  // field types and members
  using _a_type =
    float;
  _a_type a;
  using _b_type =
    float;
  _b_type b;
  using _c_type =
    float;
  _c_type c;
  using _nav_state_type =
    unsigned char;
  _nav_state_type nav_state;
  using _module_state_type =
    unsigned char;
  _module_state_type module_state;

  // setters for named parameter idiom
  Type & set__a(
    const float & _arg)
  {
    this->a = _arg;
    return *this;
  }
  Type & set__b(
    const float & _arg)
  {
    this->b = _arg;
    return *this;
  }
  Type & set__c(
    const float & _arg)
  {
    this->c = _arg;
    return *this;
  }
  Type & set__nav_state(
    const unsigned char & _arg)
  {
    this->nav_state = _arg;
    return *this;
  }
  Type & set__module_state(
    const unsigned char & _arg)
  {
    this->module_state = _arg;
    return *this;
  }

  // constant declarations
  static constexpr unsigned char NORMAL =
    0;
  static constexpr unsigned char ATTACKED =
    1;
  static constexpr unsigned char SIMULATED =
    0;
  static constexpr unsigned char WORKED =
    1;

  // pointer types
  using RawPtr =
    interfaces::msg::AntiSpoofing_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::AntiSpoofing_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::AntiSpoofing_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::AntiSpoofing_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::AntiSpoofing_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::AntiSpoofing_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::AntiSpoofing_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::AntiSpoofing_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::AntiSpoofing_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::AntiSpoofing_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__AntiSpoofing
    std::shared_ptr<interfaces::msg::AntiSpoofing_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__AntiSpoofing
    std::shared_ptr<interfaces::msg::AntiSpoofing_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AntiSpoofing_ & other) const
  {
    if (this->a != other.a) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    if (this->c != other.c) {
      return false;
    }
    if (this->nav_state != other.nav_state) {
      return false;
    }
    if (this->module_state != other.module_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const AntiSpoofing_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AntiSpoofing_

// alias to use template instance with default allocator
using AntiSpoofing =
  interfaces::msg::AntiSpoofing_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr unsigned char AntiSpoofing_<ContainerAllocator>::NORMAL;
template<typename ContainerAllocator>
constexpr unsigned char AntiSpoofing_<ContainerAllocator>::ATTACKED;
template<typename ContainerAllocator>
constexpr unsigned char AntiSpoofing_<ContainerAllocator>::SIMULATED;
template<typename ContainerAllocator>
constexpr unsigned char AntiSpoofing_<ContainerAllocator>::WORKED;

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__ANTI_SPOOFING__STRUCT_HPP_
