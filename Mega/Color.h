#pragma once


#include "Libs\TimerOne.h"

#define S0     6   // Please notice the Pin's define
#define S1     5
#define S2     4
#define S3     3
#define OUT    2


extern int   Color_RGBs[3];


					 
void Color_Init();


//*
void Color_GetColor();

void Color_FilterColor(int Level01, int Level02);


void Color_Count();


void Color_WB(int Level0, int Level1);   




