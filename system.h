#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <STC32G.H>

#include <intrins.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "intrins.h"

#define     MAIN_Fosc       11059200L   //定义主时钟

typedef unsigned char   u8;     //  8 bits 
typedef unsigned int    u16;    // 16 bits 
typedef unsigned long   u32;    // 32 bits 

typedef signed char     int8;   //  8 bits 
typedef signed int      int16;  // 16 bits 
typedef signed long     int32;  // 32 bits 

typedef unsigned char   uint8;  //  8 bits 
typedef unsigned int    uint16; // 16 bits 
typedef unsigned long   uint32; // 32 bits 

typedef signed char     int8_t;   //  8 bits 
typedef signed int      int16_t;  // 16 bits 
typedef signed long     int32_t;  // 32 bits 

typedef unsigned char   uint8_t;  //  8 bits 
typedef unsigned int    uint16_t; // 16 bits 
typedef unsigned long   uint32_t; // 32 bits 


//typedef unsigned long size_t;
// #define int8_t			int8
// #define int16_t		int16
// #define int32_t		int32
// #define uint8_t		uint8
// #define uint16_t		uint16
// #define uint32_t		uint32
//===================================================

#define	TRUE	1
#define	FALSE	0
#define HAL_MAX_DELAY 0xFF
//===================================================

//#define	NULL	0



void  HAL_Delay(unsigned int ms);
uint32_t HAL_GetTick();
#endif