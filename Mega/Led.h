#pragma once
#include "IncludeList.h"

//作者：Liu Weicheng 日期：2016年7月10日 
//功能 ：控制数码管的显示



//作用：初始数码管 请在主文件的setup函数里调用
void Led_Init();
//用于显示数字
//x:要显示的数字 传人0到9的数字
void Led_ShowNumber(int x);
//是否显示小树点 
//传入YES（1）就显示 传入NO（0）就不显示
void dispDec(int x);

//清空所有led的数字
void Led_Clear();

void zero(); void  one(); void two(); void three(); void four(); void five(); void six(); void seven(); void eight(); void nine();

#define led_a  27
#define led_b  29
#define led_c  16
#define led_d  35
#define led_e  23
#define led_f   31
#define led_g   37
#define led_p   16

