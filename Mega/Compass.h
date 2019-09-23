#pragma once


#include <Arduino.h>
#include "Libs\HMC5883L.h"


#include "Compass.h"

extern HMC5883L digicomp;

extern float X_max;  //X��������
extern float X_min;  //X����С����

extern float Y_max;  //Y��������
extern float Y_min;  //Y����С����

extern float X_offset;  //X��ƫ��
extern float Y_offset;  //Y��ƫ��

void Compass_Init();



void Compass_calibRead();

void Compass_calibration();


float Compass_Read();  //�õ�ƫ���˾Ϳ��Զ�����
