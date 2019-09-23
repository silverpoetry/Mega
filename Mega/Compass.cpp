#include "Compass.h"

 HMC5883L digicomp;

float X_max = 0.0;  //X轴最大读数
float X_min = 0.0;  //X轴最小读数

float Y_max = 0.0;  //Y轴最大读数
float Y_min = 0.0;  //Y轴最小读数

float X_offset = 0.0;  //X轴偏移
float Y_offset = 0.0;  //Y轴偏移

void Compass_Init()
{
	int i = 3;
	//尝试四次
	while (!digicomp.begin()&&i>=0)
	{
		
		delay(500);
		i--;
	}
//	if(i!=0)Console_WriteLine("Compass ready");

}


void Compass_calibRead() //指南针读数
{
	Vector scaled2 = digicomp.readRaw();

	if ((abs(scaled2.XAxis) < 500) && (abs(scaled2.YAxis) < 500) && (abs(scaled2.ZAxis) < 500)) //这行对于我很重要，能过滤掉很多干扰，增加校准的精度。
	{  //下面几行就是读取到每个轴的最大值和最小值，然后算出相应的偏移量
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
	//digitalWrite(motor1EnPin, 0);  // 定义转弯方向，对于我的小车来说是左转，逆时针方向
	//digitalWrite(motor2EnPin, 1);

	//analogWrite(motor1, 80);  // 启动马达开始转动
	//analogWrite(motor2, 80);

	//while (i < 1000)  // 逆时针方向循环读取XY轴每个方向的值，然后算出相应的偏移量
	//{
	//	calibRead();
	//	delay(10);
	//	i++;
	//}
	Serial.println("Start jiaozhun ");

	int i = 0;
	i = 0;
	//digitalWrite(motor1EnPin, 1);  // 右转小车，顺时针方向
	//digitalWrite(motor2EnPin, 0);

	while (i < 1000)  // 再顺时针方向方向旋转测算偏移量
	{
		Compass_calibRead();
		delay(10);
		i++;
	}

	Serial.println("Jiao zhun finished");
	//analogWrite(motor1, 0);  // 停止小车，校准完成
	//analogWrite(motor2, 0);
}

float Compass_Read()  //得到偏移了就可以读数了
{
	Vector scaled = digicomp.readRaw();

	float heading = atan2(scaled.YAxis - Y_offset, scaled.XAxis - X_offset);  // 读数的时候直接减掉偏移量就可以了

																			  //float declinationAngle = 36.36/1000.0;  [这几行是考虑磁偏角的，除非真的是想
																			  //heading = heading + declinationAngle;    找地理北极，不然对方向判断用处不大]

	if (heading < 0)  heading += 2 * PI;
	if (heading > 2 * PI)  heading -= 2 * PI;

	float headingDegrees = heading * 180 / M_PI;

	return headingDegrees;
}

