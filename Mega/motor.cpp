#include "motor.h"
#include "IncludeList.h"
//��һ�ε�������ʱ�� 
unsigned  long Motor_Lasttime[2] = { 0,0 };

//���������ʱ����
unsigned long Motor_Delay[2] = { 0,0 };

//���ת���ķ���
boolean Motor_Direction[2] = { Motor_FORWARD,Motor_FORWARD };



//Ҫ�ߵĲ���
long stepsToGo = 0;
boolean enableStep = false;


//��ʼ���������
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

//index ������ 1��2
//speed ���ת�� -127-128 ��λ cm/s
void Motor_SetSpeed(char index, int speed)
{
	//16ϸ�� ����
	speed = speed * 22;
	if (index==2)
	{
		speed = -speed;
	}

	//�˶�����
	if (speed > 0)
	{
		Motor_Direction[index - 1] = Motor_FORWARD;//��ת`
	
	}
	else
	{
		Motor_Direction[index - 1] = Motor_BACK;   //��ת

	}
	digitalWrite(Pin_MotorDirction_L1, Motor_Direction[0]);
	digitalWrite(Pin_MotorDirction_L2, Motor_Direction[0]);
	digitalWrite(Pin_MotorDirction_R1, Motor_Direction[1]);
	digitalWrite(Pin_MotorDirction_R2, Motor_Direction[1]);

	//���

	//65mm�������� 30cm/s �� 300��/s 1cm/s = 10��
	//1000000/ (x*10)-2  һ�������ӳ�ʱ�� = 1�루1000000΢�룩/(����) -�ߵ�ƽ����ʱ��
	if (speed == 0)
	{
		Motor_Delay[index - 1] = 0;
	}
	else
	{
		int abs_speed = abs(speed); //��ȡ�ٶȵľ���ֵ
		Motor_Delay[index - 1] = 100000 / abs_speed - 2;
		//Serial.println(Motor_Delay[0]); Serial.println(Motor_Delay[1]);

	}




}

//ͬʱ������������ת��
void Motor_SetAllSpeed(int speed1, int speed2) 
{
	Motor_SetSpeed(1, speed1);
	Motor_SetSpeed(2, speed2);

}

//���ֹͣ
void Motor_Stop()
{
	Motor_SetSpeed(1, 0);
	Motor_SetSpeed(2, 0);

}

//��ָ��ʱ��
//speed ���ת�� -127-128 ��λ cm/s
//time �ߵ�ʱ�䣬��λ ����
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


//��һ�����ٶ���һ���ľ���
//speed: �ٶȣ���λmm/s 
//steps ���ߵľ��룬��λ0.1cm
void Motor_GoSteps(int speed, int steps) {

	enableStep = true; //��������
	stepsToGo = steps ; //��¼Ҫ�ߵĲ���
	Motor_SetAllSpeed(speed, speed);//�����ٶ�
}




//������ʱ��������
void Motor_Go()
{


	unsigned long nowTime = micros();
	//if (enableStep)
	if (false)//��������Ʋ�ģʽ
	{
		if (Motor_Delay[0] != 0) {
			if (nowTime - Motor_Lasttime[0] >= Motor_Delay[0])
			{
				//���������һ���½�����Ϊһ�����壬һ��������һ����1.8�ȣ�

				stepsToGo--; //������һ��
				digitalWrite(Pin_Motor_L1, HIGH);
				digitalWrite(Pin_Motor_L2, HIGH);
				delayMicroseconds(2);    //���ӳ�
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
			Motor_SetAllSpeed(0, 0);//ֹͣ���
		}
	}
	else
	{ //����ģʽ
		if (Motor_Delay[0] != 0) {
			if (nowTime - Motor_Lasttime[0] >= Motor_Delay[0])
			{
				//���������һ���½�����Ϊһ�����壬һ��������һ����1.8�ȣ�


				digitalWrite(Pin_Motor_L1, HIGH);
				digitalWrite(Pin_Motor_L2, HIGH);
				delayMicroseconds(2);    //���ӳ�
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



