// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:msg/Ins.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/ins__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
interfaces__msg__Ins__init(interfaces__msg__Ins * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    interfaces__msg__Ins__fini(msg);
    return false;
  }
  // status
  // pitch
  // roll
  // course
  // w_x
  // w_y
  // w_z
  // a_x
  // a_y
  // a_z
  // gps_speed
  // gps_track_angle
  // gps_satellite_number
  // altitude
  // latitude
  // longitude
  // gps_utc_date
  // utc_time
  // targeting
  // temperature
  return true;
}

void
interfaces__msg__Ins__fini(interfaces__msg__Ins * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // status
  // pitch
  // roll
  // course
  // w_x
  // w_y
  // w_z
  // a_x
  // a_y
  // a_z
  // gps_speed
  // gps_track_angle
  // gps_satellite_number
  // altitude
  // latitude
  // longitude
  // gps_utc_date
  // utc_time
  // targeting
  // temperature
}

interfaces__msg__Ins *
interfaces__msg__Ins__create()
{
  interfaces__msg__Ins * msg = (interfaces__msg__Ins *)malloc(sizeof(interfaces__msg__Ins));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__msg__Ins));
  bool success = interfaces__msg__Ins__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
interfaces__msg__Ins__destroy(interfaces__msg__Ins * msg)
{
  if (msg) {
    interfaces__msg__Ins__fini(msg);
  }
  free(msg);
}


bool
interfaces__msg__Ins__Sequence__init(interfaces__msg__Ins__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  interfaces__msg__Ins * data = NULL;
  if (size) {
    data = (interfaces__msg__Ins *)calloc(size, sizeof(interfaces__msg__Ins));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__msg__Ins__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__msg__Ins__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interfaces__msg__Ins__Sequence__fini(interfaces__msg__Ins__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__msg__Ins__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interfaces__msg__Ins__Sequence *
interfaces__msg__Ins__Sequence__create(size_t size)
{
  interfaces__msg__Ins__Sequence * array = (interfaces__msg__Ins__Sequence *)malloc(sizeof(interfaces__msg__Ins__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = interfaces__msg__Ins__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
interfaces__msg__Ins__Sequence__destroy(interfaces__msg__Ins__Sequence * array)
{
  if (array) {
    interfaces__msg__Ins__Sequence__fini(array);
  }
  free(array);
}
