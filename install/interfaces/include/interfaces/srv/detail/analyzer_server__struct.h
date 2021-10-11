// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:srv/AnalyzerServer.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__ANALYZER_SERVER__STRUCT_H_
#define INTERFACES__SRV__DETAIL__ANALYZER_SERVER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/AnalyzerServer in the package interfaces.
typedef struct interfaces__srv__AnalyzerServer_Request
{
  double time;
  double pitch;
  double roll;
  double course;
  double w_x;
  double w_y;
  double w_z;
  double a_x;
  double a_y;
  double a_z;
  double gps_speed;
  double gps_track_angle;
  uint16_t gps_satellite_number;
  double altitude;
  double latitude;
  double longitude;
  double gps_utc_date;
  double utc_time;
  int16_t targeting;
  uint16_t temperature;
} interfaces__srv__AnalyzerServer_Request;

// Struct for a sequence of interfaces__srv__AnalyzerServer_Request.
typedef struct interfaces__srv__AnalyzerServer_Request__Sequence
{
  interfaces__srv__AnalyzerServer_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__AnalyzerServer_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error_description'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/AnalyzerServer in the package interfaces.
typedef struct interfaces__srv__AnalyzerServer_Response
{
  bool check_result;
  int64_t error_code;
  rosidl_runtime_c__String error_description;
} interfaces__srv__AnalyzerServer_Response;

// Struct for a sequence of interfaces__srv__AnalyzerServer_Response.
typedef struct interfaces__srv__AnalyzerServer_Response__Sequence
{
  interfaces__srv__AnalyzerServer_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__srv__AnalyzerServer_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__SRV__DETAIL__ANALYZER_SERVER__STRUCT_H_
