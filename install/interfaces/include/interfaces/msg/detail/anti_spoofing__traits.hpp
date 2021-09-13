// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/AntiSpoofing.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ANTI_SPOOFING__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__ANTI_SPOOFING__TRAITS_HPP_

#include "interfaces/msg/detail/anti_spoofing__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::msg::AntiSpoofing>()
{
  return "interfaces::msg::AntiSpoofing";
}

template<>
inline const char * name<interfaces::msg::AntiSpoofing>()
{
  return "interfaces/msg/AntiSpoofing";
}

template<>
struct has_fixed_size<interfaces::msg::AntiSpoofing>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::AntiSpoofing>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::AntiSpoofing>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__ANTI_SPOOFING__TRAITS_HPP_
