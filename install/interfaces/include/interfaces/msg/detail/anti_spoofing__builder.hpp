// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/AntiSpoofing.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ANTI_SPOOFING__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__ANTI_SPOOFING__BUILDER_HPP_

#include "interfaces/msg/detail/anti_spoofing__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_AntiSpoofing_module_state
{
public:
  explicit Init_AntiSpoofing_module_state(::interfaces::msg::AntiSpoofing & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::AntiSpoofing module_state(::interfaces::msg::AntiSpoofing::_module_state_type arg)
  {
    msg_.module_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::AntiSpoofing msg_;
};

class Init_AntiSpoofing_nav_state
{
public:
  explicit Init_AntiSpoofing_nav_state(::interfaces::msg::AntiSpoofing & msg)
  : msg_(msg)
  {}
  Init_AntiSpoofing_module_state nav_state(::interfaces::msg::AntiSpoofing::_nav_state_type arg)
  {
    msg_.nav_state = std::move(arg);
    return Init_AntiSpoofing_module_state(msg_);
  }

private:
  ::interfaces::msg::AntiSpoofing msg_;
};

class Init_AntiSpoofing_c
{
public:
  explicit Init_AntiSpoofing_c(::interfaces::msg::AntiSpoofing & msg)
  : msg_(msg)
  {}
  Init_AntiSpoofing_nav_state c(::interfaces::msg::AntiSpoofing::_c_type arg)
  {
    msg_.c = std::move(arg);
    return Init_AntiSpoofing_nav_state(msg_);
  }

private:
  ::interfaces::msg::AntiSpoofing msg_;
};

class Init_AntiSpoofing_b
{
public:
  explicit Init_AntiSpoofing_b(::interfaces::msg::AntiSpoofing & msg)
  : msg_(msg)
  {}
  Init_AntiSpoofing_c b(::interfaces::msg::AntiSpoofing::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_AntiSpoofing_c(msg_);
  }

private:
  ::interfaces::msg::AntiSpoofing msg_;
};

class Init_AntiSpoofing_a
{
public:
  Init_AntiSpoofing_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AntiSpoofing_b a(::interfaces::msg::AntiSpoofing::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_AntiSpoofing_b(msg_);
  }

private:
  ::interfaces::msg::AntiSpoofing msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::AntiSpoofing>()
{
  return interfaces::msg::builder::Init_AntiSpoofing_a();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__ANTI_SPOOFING__BUILDER_HPP_
