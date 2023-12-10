/*
Name :M5_Autonomous_Car_TEAM
Date :25/08/2023 
Breif : DATA TYPES
Version :1.0

*/


#ifndef STD_TYPE_H
#define STD_TYPE_H

typedef unsigned char           u8;
typedef signed char             s8;

typedef unsigned short int     u16;
typedef signed short int       s16;

typedef unsigned long int      u32;
typedef signed long int        s32;

typedef unsigned long          u64;
typedef signed long            s64; 

typedef float                  f32;
typedef double                 f64;
typedef long double            f128;

typedef enum {
	           FALSE ,
			   TRUE 
	          }bool;

#define NULL                   (void*)0

#endif