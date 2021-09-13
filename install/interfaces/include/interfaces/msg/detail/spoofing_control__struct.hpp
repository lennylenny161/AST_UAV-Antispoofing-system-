// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/SpoofingControl.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__SPOOFING_CONTROL__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__SPOOFING_CONTROL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__SpoofingControl __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__SpoofingControl __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SpoofingControl_
{
  using Type = SpoofingControl_<ContainerAllocator>;

  explicit SpoofingControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0.0f;
      this->b = 0.0f;
      this->c = 0.0f;
      this->spoof_cntrl_state = 0;
    }
  }

  explicit SpoofingControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0.0f;
      this->b = 0.0f;
      this->c = 0.0f;
      this->spoof_cntrl_state = 0;
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
  using _spoof_cntrl_state_type =
    unsigned char;
  _spoof_cntrl_state_type spoof_cntrl_state;

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
  Type & set__spoof_cntrl_state(
    const unsigned char & _arg)
  {
    this->spoof_cntrl_state = _arg;
    return *this;
  }

  // constant declarations
  static constexpr unsigned char ON =
    0;
  static constexpr unsigned char OFF =
    1;

  // pointer types
  using RawPtr =
    interfaces::msg::SpoofingControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::SpoofingControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::SpoofingControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::SpoofingControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::SpoofingControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::SpoofingControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::SpoofingControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::SpoofingControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::SpoofingControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::SpoofingControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__SpoofingControl
    std::shared_ptr<interfaces::msg::SpoofingControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__SpoofingControl
    std::shared_ptr<interfaces::msg::SpoofingControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SpoofingControl_ & other) const
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
    if (this->spoof_cntrl_state != other.spoof_cntrl_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const SpoofingControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SpoofingControl_

// alias to use template instance with default allocator
using SpoofingControl =
  interfaces::msg::SpoofingControl_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr unsigned char SpoofingControl_<ContainerAllocator>::ON;
template<typename ContainerAllocator>
constexpr unsigned char SpoofingControl_<ContainerAllocator>::OFF;

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__SPOOFING_CONTROL__STRUCT_HPP_
