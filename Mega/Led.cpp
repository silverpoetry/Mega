#include "Led.h"
#include "IncludeList.h"


//��ʼ�������
void Led_Init() {
	pinMode(led_a, OUTPUT);
	pinMode(led_b, OUTPUT);
	pinMode(led_c, OUTPUT);
	pinMode(led_d, OUTPUT);
	pinMode(led_e, OUTPUT);
	pinMode(led_f, OUTPUT);
	pinMode(led_g, OUTPUT);
	pinMode(led_p, OUTPUT);
	Led_Clear();

}




//������ʾ����
//x:Ҫ��ʾ������ ����0��9������
void Led_ShowNumber(int x)
{
	switch (x)
	{
	default:
		zero();
		break;
	case 1:
		one();
		break;
	case 2:
		two();
		break;
	case 3:
		three();
		break;
	case 4:
		four();
		break;
	case 5:
		five();
		break;
	case 6:
		six();
		break;
	case 7:
		seven();
		break;
	case 8:
		eight();
		break;
	case 9:
		nine();
		break;
	}
}


#define YES 1
#define NO 0
//�Ƿ���ʾС���� 
//����YES��1������ʾ ����NO��0���Ͳ���ʾ
void dispDec(int x)
{
	digitalWrite(led_p, x);

}


//�������led������

//�������led������
void Led_Clear()
{
	digitalWrite(led_a, HIGH);
	digitalWrite(led_b, HIGH);
	digitalWrite(led_c, HIGH);
	digitalWrite(led_d, HIGH);
	digitalWrite(led_e, HIGH);
	digitalWrite(led_f, HIGH);
	digitalWrite(led_g, HIGH);
	digitalWrite(led_p, HIGH);
}




#pragma region ��������
void zero()
{
	digitalWrite(led_a, LOW);
	digitalWrite(led_b, LOW);
	digitalWrite(led_c, LOW);
	digitalWrite(led_d, LOW);
	digitalWrite(led_e, LOW);
	digitalWrite(led_f, LOW);
	digitalWrite(led_g, HIGH);
}
void one()
{
	digitalWrite(led_a, HIGH);
	digitalWrite(led_b, LOW);
	digitalWrite(led_c, LOW);
	digitalWrite(led_d, HIGH);
	digitalWrite(led_e, HIGH);
	digitalWrite(led_f, HIGH);
	digitalWrite(led_g, HIGH);
}
void two()
{
	digitalWrite(led_a, LOW);
	digitalWrite(led_b, LOW);
	digitalWrite(led_c, HIGH);
	digitalWrite(led_d, LOW);
	digitalWrite(led_e, LOW);
	digitalWrite(led_f, HIGH);
	digitalWrite(led_g, LOW);
}
void three()
{
	digitalWrite(led_a, LOW);
	digitalWrite(led_b, LOW);
	digitalWrite(led_c, LOW);
	digitalWrite(led_d, LOW);
	digitalWrite(led_e, HIGH);
	digitalWrite(led_f, HIGH);
	digitalWrite(led_g, LOW);
}
void four()
{
	digitalWrite(led_a, HIGH);
	digitalWrite(led_b, LOW);
	digitalWrite(led_c, LOW);
	digitalWrite(led_d, HIGH);
	digitalWrite(led_e, HIGH);
	digitalWrite(led_f, LOW);
	digitalWrite(led_g, LOW);
}
void five()
{
	digitalWrite(led_a, LOW);
	digitalWrite(led_b, HIGH);
	digitalWrite(led_c, LOW);
	digitalWrite(led_d, LOW);
	digitalWrite(led_e, HIGH);
	digitalWrite(led_f, LOW);
	digitalWrite(led_g, LOW);
}
void six()
{
	digitalWrite(led_a, LOW);
	digitalWrite(led_b, HIGH);
	digitalWrite(led_c, LOW);
	digitalWrite(led_d, LOW);
	digitalWrite(led_e, LOW);
	digitalWrite(led_f, LOW);
	digitalWrite(led_g, LOW);
}
void seven()
{
	digitalWrite(led_a, LOW);
	digitalWrite(led_b, LOW);
	digitalWrite(led_c, LOW);
	digitalWrite(led_d, HIGH);
	digitalWrite(led_e, HIGH);
	digitalWrite(led_f, HIGH);
	digitalWrite(led_g, HIGH);
}
void eight()
{
	digitalWrite(led_a, LOW);
	digitalWrite(led_b, LOW);
	digitalWrite(led_c, LOW);
	digitalWrite(led_d, LOW);
	digitalWrite(led_e, LOW);
	digitalWrite(led_f, LOW);
	digitalWrite(led_g, LOW);
}
void nine()
{
	digitalWrite(led_a, LOW);
	digitalWrite(led_b, LOW);
	digitalWrite(led_c, LOW);
	digitalWrite(led_d, LOW);
	digitalWrite(led_e, HIGH);
	digitalWrite(led_f, LOW);
	digitalWrite(led_g, LOW);
}


#pragma endregion

