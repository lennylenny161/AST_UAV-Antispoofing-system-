// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:msg/SpoofingControl.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/spoofing_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
interfaces__msg__SpoofingControl__init(interfaces__msg__SpoofingControl * msg)
{
  if (!msg) {
    return false;
  }
  // a
  // b
  // c
  // spoof_cntrl_state
  return true;
}

void
interfaces__msg__SpoofingControl__fini(interfaces__msg__SpoofingControl * msg)
{
  if (!msg) {
    return;
  }
  // a
  // b
  // c
  // spoof_cntrl_state
}

interfaces__msg__SpoofingControl *
interfaces__msg__SpoofingControl__create()
{
  interfaces__msg__SpoofingControl * msg = (interfaces__msg__SpoofingControl *)malloc(sizeof(interfaces__msg__SpoofingControl));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__msg__SpoofingControl));
  bool success = interfaces__msg__SpoofingControl__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
interfaces__msg__SpoofingControl__destroy(interfaces__msg__SpoofingControl * msg)
{
  if (msg) {
    interfaces__msg__SpoofingControl__fini(msg);
  }
  free(msg);
}


bool
interfaces__msg__SpoofingControl__Sequence__init(interfaces__msg__SpoofingControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  interfaces__msg__SpoofingControl * data = NULL;
  if (size) {
    data = (interfaces__msg__SpoofingControl *)calloc(size, sizeof(interfaces__msg__SpoofingControl));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__msg__SpoofingControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__msg__SpoofingControl__fini(&data[i - 1]);
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
interfaces__msg__SpoofingControl__Sequence__fini(interfaces__msg__SpoofingControl__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interfaces__msg__SpoofingControl__fini(&array->data[i]);
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

interfaces__msg__SpoofingControl__Sequence *
interfaces__msg__SpoofingControl__Sequence__create(size_t size)
{
  interfaces__msg__SpoofingControl__Sequence * array = (interfaces__msg__SpoofingControl__Sequence *)malloc(sizeof(interfaces__msg__SpoofingControl__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = interfaces__msg__SpoofingControl__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
interfaces__msg__SpoofingControl__Sequence__destroy(interfaces__msg__SpoofingControl__Sequence * array)
{
  if (array) {
    interfaces__msg__SpoofingControl__Sequence__fini(array);
  }
  free(array);
}
