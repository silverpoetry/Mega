#pragma once
#include "IncludeList.h"

//���ߣ�Liu Weicheng ���ڣ�2016��7��10�� 
//���� ����������ܵ���ʾ



//���ã���ʼ����� �������ļ���setup���������
void Led_Init();
//������ʾ����
//x:Ҫ��ʾ������ ����0��9������
void Led_ShowNumber(int x);
//�Ƿ���ʾС���� 
//����YES��1������ʾ ����NO��0���Ͳ���ʾ
void dispDec(int x);

//�������led������
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

