// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/AnalyzerCallback.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ANALYZER_CALLBACK__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__ANALYZER_CALLBACK__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__AnalyzerCallback __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__AnalyzerCallback __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AnalyzerCallback_
{
  using Type = AnalyzerCallback_<ContainerAllocator>;

  explicit AnalyzerCallback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->check_result = false;
      this->error_code = 0ll;
      this->error_description = "";
    }
  }

  explicit AnalyzerCallback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    interfaces::msg::AnalyzerCallback_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::AnalyzerCallback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::AnalyzerCallback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::AnalyzerCallback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::AnalyzerCallback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::AnalyzerCallback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::AnalyzerCallback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::AnalyzerCallback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::AnalyzerCallback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::AnalyzerCallback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__AnalyzerCallback
    std::shared_ptr<interfaces::msg::AnalyzerCallback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__AnalyzerCallback
    std::shared_ptr<interfaces::msg::AnalyzerCallback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AnalyzerCallback_ & other) const
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
  bool operator!=(const AnalyzerCallback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AnalyzerCallback_

// alias to use template instance with default allocator
using AnalyzerCallback =
  interfaces::msg::AnalyzerCallback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__ANALYZER_CALLBACK__STRUCT_HPP_
