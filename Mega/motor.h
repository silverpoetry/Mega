#pragma once
#include <Arduino.h>


#define Pin_Motor_L1 A6
#define Pin_Motor_L2 A0


#define Pin_Motor_R1 26
#define Pin_Motor_R2 36


#define Pin_MotorDirction_L1 A7
#define Pin_MotorDirction_L2 A1
#define Pin_MotorDirction_R1 28
#define Pin_MotorDirction_R2 34

#define Motor_FORWARD 1
#define  Motor_BACK 0



//一下数组的零号元素均代表一号电机组(左侧的两个电机)，一号元素代表右侧两个电机

extern unsigned long Motor_Lasttime[2]; //上一次电机跳变的时间 

extern unsigned long Motor_Delay[2];//两次跳变的时间间隔

extern boolean Motor_Direction[2] ;//电机转动的方向

void Motor_Init();

void Motor_SetAllSpeed(int speed1, int speed2);

void Motor_GoSteps(int speed, int steps);

void Motor_Stop();





void Motor_SetSpeed(char index ,int speed);

void Motor_Go();
void Motor_GoTime(int time, char speed1, char speed2);

