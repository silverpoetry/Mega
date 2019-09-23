#pragma once
#include "IncludeList.h"

void LT(int speed, int t);
void LT(int speed, int t,int outtime);
void RT(int speed, int t);
void RT(int speed, int t, int outtime);
void ST(int speed);
void ST2(int speed);
void ST(int speed,int sensorvalue);
void GT(int speed, int t);
void GT(int speed, int t,int gong_speed);
void Motor_Sensor(int HuiduId, int speed1, int speed2);
void Motor_Sensor(int HuiduId, int speed1, int speed2, int outtime);

void go_Line(int speed);
void go_line_back(int speed);
void Goline_Adjust();
extern int flag;
extern int Forward_Speed;//前进速度
extern int Turn_Speed;//转弯速度
