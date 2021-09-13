// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/SpoofingControl.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__SPOOFING_CONTROL__STRUCT_H_
#define INTERFACES__MSG__DETAIL__SPOOFING_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'ON'.
enum
{
  interfaces__msg__SpoofingControl__ON = 0
};

/// Constant 'OFF'.
enum
{
  interfaces__msg__SpoofingControl__OFF = 1
};

// Struct defined in msg/SpoofingControl in the package interfaces.
typedef struct interfaces__msg__SpoofingControl
{
  float a;
  float b;
  float c;
  uint8_t spoof_cntrl_state;
} interfaces__msg__SpoofingControl;

// Struct for a sequence of interfaces__msg__SpoofingControl.
typedef struct interfaces__msg__SpoofingControl__Sequence
{
  interfaces__msg__SpoofingControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__SpoofingControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__SPOOFING_CONTROL__STRUCT_H_
