// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/AnalyzerCallback.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ANALYZER_CALLBACK__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__ANALYZER_CALLBACK__BUILDER_HPP_

#include "interfaces/msg/detail/analyzer_callback__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_AnalyzerCallback_error_description
{
public:
  explicit Init_AnalyzerCallback_error_description(::interfaces::msg::AnalyzerCallback & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::AnalyzerCallback error_description(::interfaces::msg::AnalyzerCallback::_error_description_type arg)
  {
    msg_.error_description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::AnalyzerCallback msg_;
};

class Init_AnalyzerCallback_error_code
{
public:
  explicit Init_AnalyzerCallback_error_code(::interfaces::msg::AnalyzerCallback & msg)
  : msg_(msg)
  {}
  Init_AnalyzerCallback_error_description error_code(::interfaces::msg::AnalyzerCallback::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_AnalyzerCallback_error_description(msg_);
  }

private:
  ::interfaces::msg::AnalyzerCallback msg_;
};

class Init_AnalyzerCallback_check_result
{
public:
  Init_AnalyzerCallback_check_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AnalyzerCallback_error_code check_result(::interfaces::msg::AnalyzerCallback::_check_result_type arg)
  {
    msg_.check_result = std::move(arg);
    return Init_AnalyzerCallback_error_code(msg_);
  }

private:
  ::interfaces::msg::AnalyzerCallback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::AnalyzerCallback>()
{
  return interfaces::msg::builder::Init_AnalyzerCallback_check_result();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__ANALYZER_CALLBACK__BUILDER_HPP_
