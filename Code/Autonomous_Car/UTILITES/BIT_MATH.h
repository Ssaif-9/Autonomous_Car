/*
Name :SEIF EL_DIN SULTAN
Date :25/08/2023
Breif : BIT MATH
Version :1.0

*/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)
#define TGL_BIT(REG,BIT) REG^=(1<<BIT)
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)              //(REG&(1<<BIT)>>BIT)

#define SET_REG(REG) REG|=0xff
#define CLR_REG(REG) REG&=0x00
#define TGL_REG(REG) REG^=0xff






#endif