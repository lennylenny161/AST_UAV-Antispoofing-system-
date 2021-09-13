// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/Ins.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__INS__STRUCT_H_
#define INTERFACES__MSG__DETAIL__INS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/Ins in the package interfaces.
typedef struct interfaces__msg__Ins
{
  uint8_t status;
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
  double gps_satellite_number;
  double altitude;
  double latitude;
  double longitude;
  double gps_utc_date;
  double utc_time;
  uint16_t targeting;
  uint16_t temperature;
} interfaces__msg__Ins;

// Struct for a sequence of interfaces__msg__Ins.
typedef struct interfaces__msg__Ins__Sequence
{
  interfaces__msg__Ins * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__Ins__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__INS__STRUCT_H_
