#include "Color.h"


#include "Libs\TimerOne.h"

int   Color_RGBs[3];


int   g_count = 0;    //计数值
int   g_flag = 0;     //进度标志



					
void Color_Init()
{
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
	pinMode(OUT, INPUT);

	digitalWrite(S0, LOW);  
	digitalWrite(S1, HIGH);





}

// 选择通道
void Color_FilterColor(int Level01, int Level02)
{
	if (Level01 != 0)
		Level01 = HIGH;

	if (Level02 != 0)
		Level02 = HIGH;

	digitalWrite(S2, Level01);
	digitalWrite(S3, Level02);
}

//脉冲计数
void Color_Count()
{
	g_count++;
}



bool isset=false;
//读取颜色 耗时为设定采样时间的三倍(默认是3秒)
//数据保存在Color_RGBs里
void Color_GetColor()
{
	switch (g_flag)
	{
	case 0:
		if (!isset)
		{
			isset = true;
			Timer1.attachInterrupt(Color_GetColor);//开启定时器和中断
			attachInterrupt(0, Color_Count, RISING);
	

			Color_WB(LOW, LOW);//打开红色通道
		}
		
		break;
	case 1:
	
		Color_RGBs[0] = g_count;
		Color_WB(HIGH, HIGH);            //Filter without Green
		break;
	case 2:

		Color_RGBs[1] = g_count;
		Color_WB(LOW, HIGH);             //Filter without Blue
		break;

	case 3:
	
		Color_RGBs[2] = g_count;
		Color_WB(HIGH, LOW);             //关闭通道
		break;
	default:
	
		Timer1.detachInterrupt();//关闭计时器和中断
		detachInterrupt(0);
		isset = false;
		g_count = 0;
		g_flag = 0;
		break;
	}
}


//开启颜色通道 并且设置定时器
//LOWLOW（红） HH(绿) HL（蓝）
void Color_WB(int Level0, int Level1)      
{
	g_count = 0;
	g_flag++;
	Color_FilterColor(Level0, Level1);

	Timer1.setPeriod(1000000);   //设置采样时间         
}

bool Color_IsRed()
{

}