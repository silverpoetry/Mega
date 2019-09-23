#include "Compass.h"

 HMC5883L digicomp;

float X_max = 0.0;  //X��������
float X_min = 0.0;  //X����С����

float Y_max = 0.0;  //Y��������
float Y_min = 0.0;  //Y����С����

float X_offset = 0.0;  //X��ƫ��
float Y_offset = 0.0;  //Y��ƫ��

void Compass_Init()
{
	int i = 3;
	//�����Ĵ�
	while (!digicomp.begin()&&i>=0)
	{
		
		delay(500);
		i--;
	}
//	if(i!=0)Console_WriteLine("Compass ready");

}


void Compass_calibRead() //ָ�������
{
	Vector scaled2 = digicomp.readRaw();

	if ((abs(scaled2.XAxis) < 500) && (abs(scaled2.YAxis) < 500) && (abs(scaled2.ZAxis) < 500)) //���ж����Һ���Ҫ���ܹ��˵��ܶ���ţ�����У׼�ľ��ȡ�
	{  //���漸�о��Ƕ�ȡ��ÿ��������ֵ����Сֵ��Ȼ�������Ӧ��ƫ����
		if (scaled2.XAxis > X_max) { X_max = scaled2.XAxis; }
		if (scaled2.YAxis > Y_max) { Y_max = scaled2.YAxis; }

		if (scaled2.XAxis < X_min) { X_min = scaled2.XAxis; }
		if (scaled2.YAxis < Y_min) { Y_min = scaled2.YAxis; }

		X_offset = (X_max + X_min) / 2.0;
		Y_offset = (Y_max + Y_min) / 2.0;
	}
}

void Compass_calibration()
{
	//int i = 0;
	//digitalWrite(motor1EnPin, 0);  // ����ת�䷽�򣬶����ҵ�С����˵����ת����ʱ�뷽��
	//digitalWrite(motor2EnPin, 1);

	//analogWrite(motor1, 80);  // ������￪ʼת��
	//analogWrite(motor2, 80);

	//while (i < 1000)  // ��ʱ�뷽��ѭ����ȡXY��ÿ�������ֵ��Ȼ�������Ӧ��ƫ����
	//{
	//	calibRead();
	//	delay(10);
	//	i++;
	//}
	Serial.println("Start jiaozhun ");

	int i = 0;
	i = 0;
	//digitalWrite(motor1EnPin, 1);  // ��תС����˳ʱ�뷽��
	//digitalWrite(motor2EnPin, 0);

	while (i < 1000)  // ��˳ʱ�뷽������ת����ƫ����
	{
		Compass_calibRead();
		delay(10);
		i++;
	}

	Serial.println("Jiao zhun finished");
	//analogWrite(motor1, 0);  // ֹͣС����У׼���
	//analogWrite(motor2, 0);
}

float Compass_Read()  //�õ�ƫ���˾Ϳ��Զ�����
{
	Vector scaled = digicomp.readRaw();

	float heading = atan2(scaled.YAxis - Y_offset, scaled.XAxis - X_offset);  // ������ʱ��ֱ�Ӽ���ƫ�����Ϳ�����

																			  //float declinationAngle = 36.36/1000.0;  [�⼸���ǿ��Ǵ�ƫ�ǵģ������������
																			  //heading = heading + declinationAngle;    �ҵ���������Ȼ�Է����ж��ô�����]

	if (heading < 0)  heading += 2 * PI;
	if (heading > 2 * PI)  heading -= 2 * PI;

	float headingDegrees = heading * 180 / M_PI;

	return headingDegrees;
}

