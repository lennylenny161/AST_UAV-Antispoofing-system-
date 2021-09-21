// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/AnalyzerCallback.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ANALYZER_CALLBACK__STRUCT_H_
#define INTERFACES__MSG__DETAIL__ANALYZER_CALLBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'error_description'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/AnalyzerCallback in the package interfaces.
typedef struct interfaces__msg__AnalyzerCallback
{
  bool check_result;
  int64_t error_code;
  rosidl_runtime_c__String error_description;
} interfaces__msg__AnalyzerCallback;

// Struct for a sequence of interfaces__msg__AnalyzerCallback.
typedef struct interfaces__msg__AnalyzerCallback__Sequence
{
  interfaces__msg__AnalyzerCallback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__AnalyzerCallback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__ANALYZER_CALLBACK__STRUCT_H_
