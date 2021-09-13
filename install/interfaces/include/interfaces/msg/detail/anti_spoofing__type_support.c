// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from interfaces:msg/AntiSpoofing.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "interfaces/msg/detail/anti_spoofing__rosidl_typesupport_introspection_c.h"
#include "interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "interfaces/msg/detail/anti_spoofing__functions.h"
#include "interfaces/msg/detail/anti_spoofing__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void AntiSpoofing__rosidl_typesupport_introspection_c__AntiSpoofing_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interfaces__msg__AntiSpoofing__init(message_memory);
}

void AntiSpoofing__rosidl_typesupport_introspection_c__AntiSpoofing_fini_function(void * message_memory)
{
  interfaces__msg__AntiSpoofing__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember AntiSpoofing__rosidl_typesupport_introspection_c__AntiSpoofing_message_member_array[5] = {
  {
    "a",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__AntiSpoofing, a),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "b",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__AntiSpoofing, b),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "c",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__AntiSpoofing, c),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "nav_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_OCTET,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__AntiSpoofing, nav_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "module_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_OCTET,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interfaces__msg__AntiSpoofing, module_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers AntiSpoofing__rosidl_typesupport_introspection_c__AntiSpoofing_message_members = {
  "interfaces__msg",  // message namespace
  "AntiSpoofing",  // message name
  5,  // number of fields
  sizeof(interfaces__msg__AntiSpoofing),
  AntiSpoofing__rosidl_typesupport_introspection_c__AntiSpoofing_message_member_array,  // message members
  AntiSpoofing__rosidl_typesupport_introspection_c__AntiSpoofing_init_function,  // function to initialize message memory (memory has to be allocated)
  AntiSpoofing__rosidl_typesupport_introspection_c__AntiSpoofing_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t AntiSpoofing__rosidl_typesupport_introspection_c__AntiSpoofing_message_type_support_handle = {
  0,
  &AntiSpoofing__rosidl_typesupport_introspection_c__AntiSpoofing_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interfaces, msg, AntiSpoofing)() {
  if (!AntiSpoofing__rosidl_typesupport_introspection_c__AntiSpoofing_message_type_support_handle.typesupport_identifier) {
    AntiSpoofing__rosidl_typesupport_introspection_c__AntiSpoofing_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &AntiSpoofing__rosidl_typesupport_introspection_c__AntiSpoofing_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
