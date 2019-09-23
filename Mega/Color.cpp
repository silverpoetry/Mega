#include "Color.h"


#include "Libs\TimerOne.h"

int   Color_RGBs[3];


int   g_count = 0;    //����ֵ
int   g_flag = 0;     //���ȱ�־



					
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

// ѡ��ͨ��
void Color_FilterColor(int Level01, int Level02)
{
	if (Level01 != 0)
		Level01 = HIGH;

	if (Level02 != 0)
		Level02 = HIGH;

	digitalWrite(S2, Level01);
	digitalWrite(S3, Level02);
}

//�������
void Color_Count()
{
	g_count++;
}



bool isset=false;
//��ȡ��ɫ ��ʱΪ�趨����ʱ�������(Ĭ����3��)
//���ݱ�����Color_RGBs��
void Color_GetColor()
{
	switch (g_flag)
	{
	case 0:
		if (!isset)
		{
			isset = true;
			Timer1.attachInterrupt(Color_GetColor);//������ʱ�����ж�
			attachInterrupt(0, Color_Count, RISING);
	

			Color_WB(LOW, LOW);//�򿪺�ɫͨ��
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
		Color_WB(HIGH, LOW);             //�ر�ͨ��
		break;
	default:
	
		Timer1.detachInterrupt();//�رռ�ʱ�����ж�
		detachInterrupt(0);
		isset = false;
		g_count = 0;
		g_flag = 0;
		break;
	}
}


//������ɫͨ�� �������ö�ʱ��
//LOWLOW���죩 HH(��) HL������
void Color_WB(int Level0, int Level1)      
{
	g_count = 0;
	g_flag++;
	Color_FilterColor(Level0, Level1);

	Timer1.setPeriod(1000000);   //���ò���ʱ��         
}

bool Color_IsRed()
{

}