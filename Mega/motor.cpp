#include "motor.h"
#include "IncludeList.h"
//上一次电机跳变的时间 
unsigned  long Motor_Lasttime[2] = { 0,0 };

//两次跳变的时间间隔
unsigned long Motor_Delay[2] = { 0,0 };

//电机转动的方向
boolean Motor_Direction[2] = { Motor_FORWARD,Motor_FORWARD };



//要走的步数
long stepsToGo = 0;
boolean enableStep = false;


//初始化步进电机
void Motor_Init()
{
	//Serial.begin(9600);
	pinMode(38, OUTPUT);

	digitalWrite(38, LOW);
	pinMode(A2, OUTPUT);

	digitalWrite(A2, LOW);
	pinMode(24, OUTPUT);

	digitalWrite(24, LOW);
	pinMode(38, OUTPUT);

	digitalWrite(38, LOW);
	pinMode(30, OUTPUT);

	digitalWrite(30, LOW);

	pinMode(Pin_Motor_L1, OUTPUT);
	pinMode(Pin_Motor_R1, OUTPUT);
	pinMode(Pin_Motor_L2, OUTPUT);
	pinMode(Pin_Motor_R2, OUTPUT);

	pinMode(Pin_MotorDirction_L1, OUTPUT);
	pinMode(Pin_MotorDirction_R1, OUTPUT);
	pinMode(Pin_MotorDirction_L2, OUTPUT);
	pinMode(Pin_MotorDirction_R2, OUTPUT);

	digitalWrite(Pin_Motor_L1, LOW);
	digitalWrite(Pin_Motor_R1, LOW);
	digitalWrite(Pin_Motor_L2, LOW);
	digitalWrite(Pin_Motor_R2, LOW);

	digitalWrite(Pin_MotorDirction_L1, Motor_FORWARD);
	digitalWrite(Pin_MotorDirction_R1, Motor_FORWARD);
	digitalWrite(Pin_MotorDirction_L2, Motor_FORWARD);
	digitalWrite(Pin_MotorDirction_R2, Motor_FORWARD);

	Motor_Lasttime[0] = micros();
	Motor_Lasttime[1] = micros();

}

//index 电机编号 1或2
//speed 电机转速 -127-128 单位 cm/s
void Motor_SetSpeed(char index, int speed)
{
	//16细分 反向
	speed = speed * 22;
	if (index==2)
	{
		speed = -speed;
	}

	//运动方向
	if (speed > 0)
	{
		Motor_Direction[index - 1] = Motor_FORWARD;//正转`
	
	}
	else
	{
		Motor_Direction[index - 1] = Motor_BACK;   //反转

	}
	digitalWrite(Pin_MotorDirction_L1, Motor_Direction[0]);
	digitalWrite(Pin_MotorDirction_L2, Motor_Direction[0]);
	digitalWrite(Pin_MotorDirction_R1, Motor_Direction[1]);
	digitalWrite(Pin_MotorDirction_R2, Motor_Direction[1]);

	//间隔

	//65mm的轮子下 30cm/s ≈ 300步/s 1cm/s = 10步
	//1000000/ (x*10)-2  一个脉冲延迟时间 = 1秒（1000000微秒）/(步数) -高电平持续时间
	if (speed == 0)
	{
		Motor_Delay[index - 1] = 0;
	}
	else
	{
		int abs_speed = abs(speed); //获取速度的绝对值
		Motor_Delay[index - 1] = 100000 / abs_speed - 2;
		//Serial.println(Motor_Delay[0]); Serial.println(Motor_Delay[1]);

	}




}

//同时设置两组电机的转速
void Motor_SetAllSpeed(int speed1, int speed2) 
{
	Motor_SetSpeed(1, speed1);
	Motor_SetSpeed(2, speed2);

}

//电机停止
void Motor_Stop()
{
	Motor_SetSpeed(1, 0);
	Motor_SetSpeed(2, 0);

}

//走指定时间
//speed 电机转速 -127-128 单位 cm/s
//time 走的时间，单位 毫秒
void Motor_GoTime(int time, char speed1, char speed2)
{
	
	Motor_SetAllSpeed(speed1, speed2);
	unsigned long now = millis();
	while (millis()-now<time)
	{
		unBeep();
		Motor_Go();
	}
	Motor_Stop();

}


//以一定的速度走一定的距离
//speed: 速度，单位mm/s 
//steps ：走的距离，单位0.1cm
void Motor_GoSteps(int speed, int steps) {

	enableStep = true; //开启计数
	stepsToGo = steps ; //记录要走的步数
	Motor_SetAllSpeed(speed, speed);//设置速度
}




//向电机按时发送脉冲
void Motor_Go()
{


	unsigned long nowTime = micros();
	//if (enableStep)
	if (false)//如果开启计步模式
	{
		if (Motor_Delay[0] != 0) {
			if (nowTime - Motor_Lasttime[0] >= Motor_Delay[0])
			{
				//步进电机讲一个下降沿视为一个脉冲，一个脉冲走一步（1.8度）

				stepsToGo--; //走完了一步
				digitalWrite(Pin_Motor_L1, HIGH);
				digitalWrite(Pin_Motor_L2, HIGH);
				delayMicroseconds(2);    //梢延迟
				digitalWrite(Pin_Motor_L1, LOW);
				digitalWrite(Pin_Motor_L2, LOW);
				Motor_Lasttime[0] = micros();


		

			}
		}
		if (Motor_Delay[1] != 0) {
			if (nowTime - Motor_Lasttime[1] >= Motor_Delay[1])
			{
				digitalWrite(Pin_Motor_R1, HIGH);
				digitalWrite(Pin_Motor_R2, HIGH);
				delayMicroseconds(2);
				digitalWrite(Pin_Motor_R1, LOW);
				digitalWrite(Pin_Motor_R2, LOW);
				
				Motor_Lasttime[1] = micros();

			}
		}
		
		if (stepsToGo==0)
		{
			enableStep = false;
			stepsToGo = 0;
			Motor_SetAllSpeed(0, 0);//停止电机
		}
	}
	else
	{ //正常模式
		if (Motor_Delay[0] != 0) {
			if (nowTime - Motor_Lasttime[0] >= Motor_Delay[0])
			{
				//步进电机讲一个下降沿视为一个脉冲，一个脉冲走一步（1.8度）


				digitalWrite(Pin_Motor_L1, HIGH);
				digitalWrite(Pin_Motor_L2, HIGH);
				delayMicroseconds(2);    //梢延迟
				digitalWrite(Pin_Motor_L1, LOW);
				digitalWrite(Pin_Motor_L2, LOW);
				Motor_Lasttime[0] = micros();

			}
		}
		if (Motor_Delay[1] != 0) {
			if (nowTime - Motor_Lasttime[1] >= Motor_Delay[1])
			{
				digitalWrite(Pin_Motor_R1, HIGH);
				digitalWrite(Pin_Motor_R2, HIGH);
				delayMicroseconds(2);
				digitalWrite(Pin_Motor_R1, LOW);
				digitalWrite(Pin_Motor_R2, LOW);
				Motor_Lasttime[1] = micros();

			}
		}
	}


}



