// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from interfaces:msg/AnalyzerCallback.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "interfaces/msg/detail/analyzer_callback__rosidl_typesupport_introspection_c.h"
#include "interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "interfaces/msg/detail/analyzer_callback__functions.h"
#include "interfaces/msg/detail/analyzer_callback__struct.h"


// Include directives for member types
// Member `error_description`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void AnalyzerCallback__rosidl_typesupport_introspection_c__AnalyzerCallback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interfaces__msg__AnalyzerCallback__init(message_memory);
}

void AnalyzerCallback__rosidl_typesupport_introspection_c__AnalyzerCallback_fini_function(void * message_memory)
{
  interfaces__msg__AnalyzerCallback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember AnalyzerCallback__rosidl_typesupport_introspection_c__AnalyzerCallback_message_member_array[3] = {
  {
    "check_result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__AnalyzerCallback, check_result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__AnalyzerCallback, error_code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_description",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__AnalyzerCallback, error_description),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers AnalyzerCallback__rosidl_typesupport_introspection_c__AnalyzerCallback_message_members = {
  "interfaces__msg",  // message namespace
  "AnalyzerCallback",  // message name
  3,  // number of fields
  sizeof(interfaces__msg__AnalyzerCallback),
  AnalyzerCallback__rosidl_typesupport_introspection_c__AnalyzerCallback_message_member_array,  // message members
  AnalyzerCallback__rosidl_typesupport_introspection_c__AnalyzerCallback_init_function,  // function to initialize message memory (memory has to be allocated)
  AnalyzerCallback__rosidl_typesupport_introspection_c__AnalyzerCallback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t AnalyzerCallback__rosidl_typesupport_introspection_c__AnalyzerCallback_message_type_support_handle = {
  0,
  &AnalyzerCallback__rosidl_typesupport_introspection_c__AnalyzerCallback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, msg, AnalyzerCallback)() {
  if (!AnalyzerCallback__rosidl_typesupport_introspection_c__AnalyzerCallback_message_type_support_handle.typesupport_identifier) {
    AnalyzerCallback__rosidl_typesupport_introspection_c__AnalyzerCallback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &AnalyzerCallback__rosidl_typesupport_introspection_c__AnalyzerCallback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
