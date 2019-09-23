

#include "Dianzhen.h"
#include "IncludeList.h"
unsigned char disp1[38][8] = {
	{ 0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 },//0
	{ 0x0,B111000,B10000,B10000,B10000,B10000,B11000 , B10000 },//1
	//{ 0x0,B111100,B100,B100,B111100,B100000,B100000,B111100 },//2
	{ 0x0,B111100,B100,B1000,B10000,B100000,B100100,B11000 },//2
	{ 0x0,B11000,B100100,B100000,B11000,B100000,B100100,B11000 },//3
	
};

void Write_Max7219_byte(char DATA)
{
	char i;
	digitalWrite(Dianzhen_cs, 0);
	for (i = 8; i >= 1; i--)
	{
		digitalWrite(Dianzhen_clk, 0);
		if ((DATA & 0x80)>0) { digitalWrite(Dianzhen_din, 1); }
		else { digitalWrite(Dianzhen_din, 0); }
		//��ȡ���λ��DIN�˿�
		DATA = DATA << 1;//����һλ
		digitalWrite(Dianzhen_clk, 1);
	}
}
void Write_Max7219(char address, char dat)
{
	digitalWrite(Dianzhen_cs, 0);
	Write_Max7219_byte(address);           //д���ַ��������ܱ��
	Write_Max7219_byte(dat);               //д�����ݣ����������ʾ���� 
	digitalWrite(Dianzhen_cs, 1);
}
void Init_MAX7219(void)
{
	Write_Max7219(0x09, 0x00);//���뷽ʽ��BCD��
	Write_Max7219(0x0a, 0x01);//���� 
	Write_Max7219(0x0b, 0x07); //ɨ����ޣ�8���������ʾ
	Write_Max7219(0x0c, 0x01);  //����ģʽ��0����ͨģʽ��1
	Write_Max7219(0x0f, 0x00);
	delay(500); //��ʾ���ԣ�1�����Խ�����������ʾ��0
}





void Dianzhen_Init() {
	pinMode(Dianzhen_cs, OUTPUT);
	pinMode(Dianzhen_clk, OUTPUT);
	pinMode(Dianzhen_din, OUTPUT);
	Init_MAX7219();
}

void Dianzhen_Shownum(int num)
{

	for (int i = 1; i<9; i++)
		Write_Max7219(i, disp1[num][i - 1]);
}
