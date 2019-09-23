#pragma once


#include <Arduino.h>
#include "Libs\HMC5883L.h"


#include "Compass.h"

extern HMC5883L digicomp;

extern float X_max;  //X轴最大读数
extern float X_min;  //X轴最小读数

extern float Y_max;  //Y轴最大读数
extern float Y_min;  //Y轴最小读数

extern float X_offset;  //X轴偏移
extern float Y_offset;  //Y轴偏移

void Compass_Init();



void Compass_calibRead();

void Compass_calibration();


float Compass_Read();  //得到偏移了就可以读数了
