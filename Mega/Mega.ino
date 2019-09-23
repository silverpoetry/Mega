//#include "Color.h"
//#include "Huidu.h"
////
/////*
//// Name:		Mega.ino
//// Created:	2017/2/24 18:57:32
//// Author:	Liu
////*/
////
////
////#include "Arduino.h"
////#include "Motor.h"
////
////
////
////// the se                                                                                                                                               tup function runs once when you press reset or power the board
////void setup() {
////	Motor_Init();
////}
////
////// the loop function runs over and over again until power down or reset
////void loop() {
////	while (true)
////	{
////
////		Motor_SetAllSpeed(20, 20);
////		delay(1000);
////	Motor_Stop();
////	delay(3000);
////	}
////}
////
////
////void setup()
////{
////	Huidu_Init();
////	Color_Init();
////	Serial.begin(9600);
////	
////
////	delay(4000);
////
////
////}
////
////void loop()
////{
////	
//////	Serial.println("sss");
////	Serial.println(Huidu_Read(1));
////	
////}
//
//#include <Wire.h> //I2C Arduino Library
//
//#define address 0x1E //0011110b, I2C 7bit address of HMC5883
//
//void setup() {
//
//	Serial.begin(9600);
//
//
//	
//}
//
//void loop() {
//	Serial.print("asda");
//}

//#include "Libs\HMC5883L.h"
//#include "Compass.h"
//#include "Console.h"
//#include "Libs\u8glib\U8glib.h"
////
////void setup()
////{
////	digicomp.begin();
////
////}
////void loop() {
////	Compass_calibration();
////	while (true)
////	{
////		Serial.println(Compass_Read());
////		delay(500);
////
////	}
////	clear_screen
//
// //Arduino master setup
//void setup(void) {
//	Console_Init();
//}
//
//// Arduino main loop
//void loop(void) {
//	
//	Console_Write("1");
//	delay(1000);
//}
#include "IncludeList.h"


void Arm_Set()
{
	Arm_Go(2, 40);
	Arm_Go(3, 90);
	Arm_Go(4, 63);
}
void Road()
{
	
	ST2(Forward_Speed);
	Motor_GoTime(200, Turn_Speed, Turn_Speed);
	Motor_GoTime(600, -Turn_Speed, Turn_Speed);
	Motor_GoTime(1900, Turn_Speed, Turn_Speed);
	Motor_GoTime(600, Turn_Speed, -Turn_Speed);
	Motor_GoTime(700, Turn_Speed, Turn_Speed);
	Motor_GoTime(500, Turn_Speed, -Turn_Speed);
	Motor_GoTime(1600, Turn_Speed, Turn_Speed);
	Motor_GoTime(900, Turn_Speed, -Turn_Speed);

	Motor_GoTime(650, Turn_Speed, Turn_Speed);
	Motor_GoTime(700, Turn_Speed, -Turn_Speed);
	Motor_GoTime(1900, Turn_Speed, Turn_Speed);
	Motor_Sensor(3, -Forward_Speed, Forward_Speed);
	/*ST(Forward_Speed);
	delay(300);
	Motor_GoTime(350, -Turn_Speed, -Turn_Speed);
*/
	/*Motor_GoTime(1500, Turn_Speed, -Turn_Speed);
	Motor_Sensor(3, -Forward_Speed, Forward_Speed);
	ST(Forward_Speed);*/

}

void All1()
{
	
	Start();
	BigDad_Fix_Left();


	RT(Forward_Speed, 800);
	GT(Forward_Speed, 400);
	Round_Right();
	Nahuijia();
	Motor_GoTime(300,Forward_Speed, Forward_Speed);
	RT(Forward_Speed, 900);
	Motor_GoTime(2000, Forward_Speed, Forward_Speed);


}
void All2()
{
	Start();
	
	Trash_Judgement_Right();
	GT(Forward_Speed, 300);
	GT(Forward_Speed, 300);
	RT(Forward_Speed, 800);
	GT(Forward_Speed, 300);
	Hit_PoliceClock_Left();
	GT(Forward_Speed, 300);
	GT(Forward_Speed, 300);
	Plant_Trees_left();
	
	RT(Forward_Speed, 800);
	GT(Forward_Speed, 300);
	Fire_Savement_Right();
	RT(Forward_Speed, 800);
	LT(Forward_Speed, 800);
	GT(Forward_Speed, 300);
	LT(Forward_Speed, 800);
	RT(Forward_Speed, 800);
	Transport_Lead_Right();
	RT(Forward_Speed, 800);
	GT(Forward_Speed, 300);
	BigDad_Fix_Left();
	RT(Forward_Speed, 800);
	GT(Forward_Speed, 300);
	Nahuijia();
	GT(Forward_Speed, 300);
	RT(Forward_Speed, 600);
	GT(Forward_Speed, 300);
	Motor_GoTime(100, Turn_Speed, -Turn_Speed);
	Motor_GoTime(1600,Forward_Speed,Forward_Speed);

	//flag = 0;
	//while (1)
	//{
	//	//HD();

	//	Motor_Go();
	//	/*if(millis()-t>200){*/
	//	if (Huidu_IsLine(1) || Huidu_IsLine(5)) {/* Serial.println("lukou"); */Beep(); Motor_Stop(); break; }
	//	else go_line_back(-Forward_Speed);
	//	/*	t = millis();
	//	}*/
	//}
	//flag = 0;;
	//Motor_GoTime(200,-Forward_Speed, -Forward_Speed);
	//BigDad_Fix_Left();
	//GT(Forward_Speed, 300);
	//GT(Forward_Speed, 300);
	//GT(Forward_Speed, 2200);


	////Motor_Sensor(3, Forward_Speed,- Forward_Speed);
	//Motor_GoTime(600, -Forward_Speed, Forward_Speed);
	//Motor_GoTime(100, Turn_Speed, Turn_Speed);
	//GT(Forward_Speed, 400);
	//Fire_Savement_Right();
}


void setup()
{

	pinMode(50, OUTPUT);
	pinMode(52, OUTPUT);
	
	Color_Init();
//	Compass_Init();
	Dianzhen_Init();
	Huidu_Init();
	Motor_Init();
	Arm_Init();
	Distance_Init();
	Beeper_Init();
	//Led_Init();
	pinMode(27, INPUT);
	pinMode(29, INPUT);
	Serial.begin(9600);
}


void loop()
{
	//Arm_Go(2, 15);
	//Arm_Go(3, 65);
	//Arm_Go(2, 45);++++
	//Arm_Go(4, 80);
	Beep();
	Beep();
	Dianzhen_Shownum(0);

	
	while (true)
	{

		if (digitalRead(27) ==0) {
			All1();
			delay(3000);
		
		}
		else if (digitalRead(29) ==0) {
			Plant_Trees_right();delay(3000);

		}
		delay(500);
	}

		while (true)
		{
			delay(300);
			//Beep();
			Huidu_ShowValue();
			//	Led_ShowNumber(0);
			unsigned char N, angel, thchar;
			short tm;
			if (Serial.available() > 0)
			{

				char c = Serial.read();

				switch (c)
				{
				case 'G':

					Beep();
					//	ST(Forward_Speed);
					GT(Forward_Speed, 400);
					break;
				case 'L':
					 tm = 0 + Serial.read() * 10 + Serial.read();
					LT(Forward_Speed, tm);
					
					break;
				case 'R':
					tm = 0 + Serial.read() * 10 + Serial.read();
					RT(Forward_Speed, tm);
					break;
				case 'S':
					ST(Forward_Speed);
					break;
				case '1':
					Motor_SetAllSpeed(20, 20);
					Serial.println("qian");
					break;
				case '2':
					Motor_SetAllSpeed(-20, -20);
					break;
				case '3':
					Motor_SetAllSpeed(-Turn_Speed, Turn_Speed);
					break;
				case '4':
					Motor_SetAllSpeed(Turn_Speed, -Turn_Speed);
					break;
				case 't':
					Motor_Stop();
				case 'D':
					N = Serial.read();
					// angel = Serial.read();
					/* Serial.print((int)N);
					 Serial.print("%%");
					 Serial.println((int)angel);*/
					Arm_Go(N, 0 + Serial.read() * 10 + Serial.read());
					/*	Serial.print((int)N);
						Serial.println((int)angel)*/
					break;
				case 'F':
					thchar = Serial.read();
					switch (thchar)
					{
					case 'L':
						Motor_GoTime(0 + Serial.read() * 10 + Serial.read(), -Turn_Speed, Turn_Speed);
						break;
					case 'R':
						Motor_GoTime(0 + Serial.read() * 10 + Serial.read(), Turn_Speed, -Turn_Speed);
						break;
					case 'F':
						Motor_GoTime(0 + Serial.read() * 10 + Serial.read(), Turn_Speed, Turn_Speed);
						break;
					default:
						break;
					}
					break;

				case 'Z':
					Arm_Reset();
					break;
				case ';':
					Goline_Adjust();
					break;
				case 'U':
					N = Serial.read();
					if (N == '1')Transport_Lead_Right();
					if (N == '2')All2();
					if (N == '3')Plant_Trees_left();
					if (N == '4')Plant_Trees_right();
					if (N == '5')Hit_PoliceClock_Right();
					if (N == '6')Hit_PoliceClock_Left();
					if (N == '7')Trash_Judgement_Left();
					if (N == '8')Trash_Judgement_Right();
					
				
				
				//	Trash_Judgement_Left();
					break;
				default:
					break;

				}



				//Serial.println(s);
				//Serial.println("9");


			}

		}

	}
	
