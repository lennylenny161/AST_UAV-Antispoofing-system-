// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/AntiSpoofing.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ANTI_SPOOFING__STRUCT_H_
#define INTERFACES__MSG__DETAIL__ANTI_SPOOFING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'NORMAL'.
enum
{
  interfaces__msg__AntiSpoofing__NORMAL = 0
};

/// Constant 'ATTACKED'.
enum
{
  interfaces__msg__AntiSpoofing__ATTACKED = 1
};

/// Constant 'SIMULATED'.
enum
{
  interfaces__msg__AntiSpoofing__SIMULATED = 0
};

/// Constant 'WORKED'.
enum
{
  interfaces__msg__AntiSpoofing__WORKED = 1
};

// Struct defined in msg/AntiSpoofing in the package interfaces.
typedef struct interfaces__msg__AntiSpoofing
{
  float a;
  float b;
  float c;
  uint8_t nav_state;
  uint8_t module_state;
} interfaces__msg__AntiSpoofing;

// Struct for a sequence of interfaces__msg__AntiSpoofing.
typedef struct interfaces__msg__AntiSpoofing__Sequence
{
  interfaces__msg__AntiSpoofing * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__AntiSpoofing__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__ANTI_SPOOFING__STRUCT_H_
