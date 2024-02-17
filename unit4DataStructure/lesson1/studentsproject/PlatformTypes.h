/*
Learn In Depth
by : Eman Elsayed 
header file for Standard types for ARM processor
*/ 

#ifndef PLATFORMTYPES_H_
#define PLATFORMTYPES_H_

//sympols
#define CPU_TYPE       CPU_TYPE_32
#define CPU_BIT_ORDER  LSB_FIRST
#define CPU_BYTE_ORDER LOW_BYTE_FIRST
//TYPES
typedef unsigned long      boolean;

typedef unsigned char      uint8;
typedef  char              sint8;

typedef unsigned short     uint16;
typedef signed short       sint16;

typedef unsigned int       uint32;
typedef signed int         sint32;

typedef unsigned long long uint64;
typedef signed long long   sint64;

  

#endif
