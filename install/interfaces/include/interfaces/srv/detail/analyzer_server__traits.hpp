// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/AnalyzerServer.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__ANALYZER_SERVER__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__ANALYZER_SERVER__TRAITS_HPP_

#include "interfaces/srv/detail/analyzer_server__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::AnalyzerServer_Request>()
{
  return "interfaces::srv::AnalyzerServer_Request";
}

template<>
inline const char * name<interfaces::srv::AnalyzerServer_Request>()
{
  return "interfaces/srv/AnalyzerServer_Request";
}

template<>
struct has_fixed_size<interfaces::srv::AnalyzerServer_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::AnalyzerServer_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::AnalyzerServer_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::AnalyzerServer_Response>()
{
  return "interfaces::srv::AnalyzerServer_Response";
}

template<>
inline const char * name<interfaces::srv::AnalyzerServer_Response>()
{
  return "interfaces/srv/AnalyzerServer_Response";
}

template<>
struct has_fixed_size<interfaces::srv::AnalyzerServer_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::srv::AnalyzerServer_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::srv::AnalyzerServer_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::AnalyzerServer>()
{
  return "interfaces::srv::AnalyzerServer";
}

template<>
inline const char * name<interfaces::srv::AnalyzerServer>()
{
  return "interfaces/srv/AnalyzerServer";
}

template<>
struct has_fixed_size<interfaces::srv::AnalyzerServer>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::AnalyzerServer_Request>::value &&
    has_fixed_size<interfaces::srv::AnalyzerServer_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::AnalyzerServer>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::AnalyzerServer_Request>::value &&
    has_bounded_size<interfaces::srv::AnalyzerServer_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::AnalyzerServer>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::AnalyzerServer_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::AnalyzerServer_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__ANALYZER_SERVER__TRAITS_HPP_
