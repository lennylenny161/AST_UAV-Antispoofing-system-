// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/SpoofingControl.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__SPOOFING_CONTROL__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__SPOOFING_CONTROL__BUILDER_HPP_

#include "interfaces/msg/detail/spoofing_control__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_SpoofingControl_spoof_cntrl_state
{
public:
  explicit Init_SpoofingControl_spoof_cntrl_state(::interfaces::msg::SpoofingControl & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::SpoofingControl spoof_cntrl_state(::interfaces::msg::SpoofingControl::_spoof_cntrl_state_type arg)
  {
    msg_.spoof_cntrl_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::SpoofingControl msg_;
};

class Init_SpoofingControl_c
{
public:
  explicit Init_SpoofingControl_c(::interfaces::msg::SpoofingControl & msg)
  : msg_(msg)
  {}
  Init_SpoofingControl_spoof_cntrl_state c(::interfaces::msg::SpoofingControl::_c_type arg)
  {
    msg_.c = std::move(arg);
    return Init_SpoofingControl_spoof_cntrl_state(msg_);
  }

private:
  ::interfaces::msg::SpoofingControl msg_;
};

class Init_SpoofingControl_b
{
public:
  explicit Init_SpoofingControl_b(::interfaces::msg::SpoofingControl & msg)
  : msg_(msg)
  {}
  Init_SpoofingControl_c b(::interfaces::msg::SpoofingControl::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_SpoofingControl_c(msg_);
  }

private:
  ::interfaces::msg::SpoofingControl msg_;
};

class Init_SpoofingControl_a
{
public:
  Init_SpoofingControl_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SpoofingControl_b a(::interfaces::msg::SpoofingControl::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_SpoofingControl_b(msg_);
  }

private:
  ::interfaces::msg::SpoofingControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::SpoofingControl>()
{
  return interfaces::msg::builder::Init_SpoofingControl_a();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__SPOOFING_CONTROL__BUILDER_HPP_
