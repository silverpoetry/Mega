#include "Line.h"


 int Forward_Speed = 38;//ǰ���ٶ�
 int Turn_Speed = 15;//ת���ٶ�
 


static int flag = 0;
void Goline_Adjust()
{

	bool LineLeft = Huidu_IsLine(1);
	bool LineRight = Huidu_IsLine(5);
	while (!(LineLeft&&LineRight)&&Time_TakeTime(350))
	{
		if (!Huidu_IsLine(1))
		{
			Motor_GoTime(2, Turn_Speed, 0);
		}
		else if (!Huidu_IsLine(5))
		{
			Motor_GoTime(2, 0, Turn_Speed);
		}

		LineLeft = Huidu_IsLine(1);
		LineRight = Huidu_IsLine(5);
	}



}


void go_line_back(int speed) // Ѳ�ߺ���
{

	int vt = Huidu_Read(2) - Huidu_Read(4);
	if (vt ==0 && flag != 20) { Motor_SetAllSpeed(speed, speed);flag = 20; }
	else if (vt > 0 && vt <= 50 && flag != 1) { Motor_SetAllSpeed(speed*0.95, speed); flag = 1; }
	else if (vt>50 && vt <= 100 && flag != 92) { Motor_SetAllSpeed(speed*0.9, speed);/* Serial.println("LLL");*/ flag = 92; }

	else if (vt>100 && vt <= 150 && flag != 2) { Motor_SetAllSpeed(speed*0.9, speed);flag = 2; }
	else if (vt>150 && vt <= 200 && flag != 3) { Motor_SetAllSpeed(speed*0.85, speed); flag = 3; }
	else if (vt>200 && vt <= 250 && flag != 4) { Motor_SetAllSpeed(speed*0.8, speed);flag = 4; }
	else if (vt>250 && vt <= 300 && flag != 5) { Motor_SetAllSpeed(speed*0.7, speed); flag = 5; }
	else if (vt>300 && vt <= 350 && flag != 6) { Motor_SetAllSpeed(speed*0.6, speed); flag = 6; }
	else if (vt>350 && vt <= 400 && flag != 7) { Motor_SetAllSpeed(speed*0.5, speed); flag = 7; }
	else if (vt>400 && vt <= 450 && flag != 8) { Motor_SetAllSpeed(speed*0.4, speed); flag = 8; }
	else if (vt>450 && flag != 9) { Motor_SetAllSpeed(speed*0.3, speed); flag = 9; }

	vt = -vt;
	if (vt>0 && vt <= 50 && flag != 10) { Motor_SetAllSpeed(speed, speed*0.95);flag = 10; }
	else if (vt>50 && vt <= 100 && flag != 91) { Motor_SetAllSpeed(speed, speed*0.9);/* Serial.println("LLL");*/ flag = 91; }

	else if (vt>100 && vt <= 150 && flag != 11) { Motor_SetAllSpeed(speed, speed*0.9); flag = 11; }
	else if (vt>150 && vt <= 200 && flag != 12) { Motor_SetAllSpeed(speed, speed*0.85);flag = 12; }
	else if (vt>200 && vt <= 250 && flag != 13) { Motor_SetAllSpeed(speed, speed*0.8);flag = 13; }
	else if (vt>250 && vt <= 300 && flag != 14) { Motor_SetAllSpeed(speed, speed*0.7); flag = 14; }
	else if (vt>300 && vt <= 350 && flag != 15) { Motor_SetAllSpeed(speed, speed*0.6);flag = 15; }
	else if (vt>350 && vt <= 400 && flag != 16) { Motor_SetAllSpeed(speed, speed*0.5); flag = 16; }
	else if (vt>400 && vt <= 450 && flag != 17) { Motor_SetAllSpeed(speed, speed*0.4);flag = 17; }
	else if (vt>450 && flag != 18) { Motor_SetAllSpeed(speed, speed*0.3); flag = 18; }
	//if (Huidu_IsLine(3))
	//{

	//	//ֱ��
	//	  Motor_SetAllSpeed(speed, speed);/* Serial.println("straight");*/ flag = 3; 
	//}
	//else {
	//	//��ת
	//	if (Huidu_Read(2) < Huidu_Read(4) ) { Motor_SetAllSpeed(speed, speed*0.4);/* Serial.println("LLL");*/ flag = 2; }
	//	//��ת
	//	else if (Huidu_Read(2) > Huidu_Read(4) ) { Motor_SetAllSpeed(speed*0.4, speed); /*Serial.println("rrr"); */flag = 4; }
	//}

}

void go_Line(int speed) //��ֱ������
{
	
	//Serial.println(Huidu_Read(3));
	//if (Huidu_Read(3)<Huidu_LineValues[2]-100)
	//{

	//	//ֱ��
	//	if (flag != 3) { Motor_SetAllSpeed(speed, speed);/* Serial.println("straight");*/ flag = 3; }
	//}
	//else {
	//	//��ת
	// if (Huidu_Read(2) < Huidu_Read(4) && flag != 2) { Motor_SetAllSpeed(speed*0.3, speed);/* Serial.println("LLL");*/ flag = 2; }
	////��ת
	//else if(Huidu_Read(2) > Huidu_Read(4) && flag != 4) { Motor_SetAllSpeed(speed, speed*0.3); /*Serial.println("rrr"); */flag = 4; }


	//}
	int vt = Huidu_Read(2) - Huidu_Read(4);
	// Motor_SetAllSpeed(speed, speed);/* Serial.println("LLL");*/
	if(vt==0&&flag!=100){ Motor_SetAllSpeed(speed, speed);/* Serial.println("LLL");*/ flag = 100; }
	 if(vt>0&&vt<=50&&flag!=1){ Motor_SetAllSpeed(speed, speed*0.95);/* Serial.println("LLL");*/ flag = 1; }
	 else if (vt>50 && vt <= 100 && flag != 91) { Motor_SetAllSpeed(speed, speed*0.9);/* Serial.println("LLL");*/ flag = 91; }

	 else if (vt>100 && vt <= 150 && flag != 2) { Motor_SetAllSpeed(speed, speed*0.9);/* Serial.println("LLL");*/ flag = 2; }
	else if (vt>150 && vt <= 200 && flag != 3) { Motor_SetAllSpeed(speed, speed*0.85);/* Serial.println("LLL");*/ flag = 3; }
	else if (vt>200 && vt <= 250 && flag != 4) { Motor_SetAllSpeed(speed, speed*0.8);/* Serial.println("LLL");*/ flag = 4; }
	else if (vt>250 && vt <= 300 && flag != 5) { Motor_SetAllSpeed(speed, speed*0.7);/* Serial.println("LLL");*/ flag = 5; }
	else if (vt>300 && vt <= 350 && flag != 6) { Motor_SetAllSpeed(speed, speed*0.6);/* Serial.println("LLL");*/ flag = 6; }
	else if (vt>350 && vt <= 400 && flag != 7) { Motor_SetAllSpeed(speed, speed*0.5);/* Serial.println("LLL");*/ flag = 7; }
	else if (vt>400 && vt <= 450 && flag != 8) { Motor_SetAllSpeed(speed, speed*0.4);/* Serial.println("LLL");*/ flag = 8; }
	else if (vt>450  && flag != 9) { Motor_SetAllSpeed(speed, speed*0.3);/* Serial.println("LLL");*/ flag = 9; }

	 vt = -vt;
	if (vt>0 && vt <= 50 && flag != 10) { Motor_SetAllSpeed(speed*0.95, speed);/* Serial.println("LLL");*/ flag = 10; }
	else if (vt>50 && vt <= 100 && flag != 92) { Motor_SetAllSpeed(speed*0.9, speed);/* Serial.println("LLL");*/ flag = 92; }

	else if (vt>100 && vt <= 150 && flag != 11) { Motor_SetAllSpeed(speed*0.9, speed);/* Serial.println("LLL");*/ flag = 11; }
	else if (vt>150 && vt <= 200 && flag != 12) { Motor_SetAllSpeed(speed*0.85, speed);/* Serial.println("LLL");*/ flag = 12; }
	else if (vt>200 && vt <= 250 && flag != 13) { Motor_SetAllSpeed(speed*0.8, speed);/* Serial.println("LLL");*/ flag = 13; }
	else if (vt>250 && vt <= 300 && flag != 14) { Motor_SetAllSpeed(speed*0.7, speed);/* Serial.println("LLL");*/ flag = 14; }
	else if (vt>300 && vt <= 350 && flag != 15) { Motor_SetAllSpeed(speed*0.6, speed);/* Serial.println("LLL");*/ flag = 15; }
	else if (vt>350 && vt <= 400 && flag != 16) { Motor_SetAllSpeed(speed*0.5, speed);/* Serial.println("LLL");*/ flag = 16; }
	else if (vt>400 && vt <= 450 && flag != 17) { Motor_SetAllSpeed(speed*0.4, speed);/* Serial.println("LLL");*/ flag = 17; }
	else if (vt>450 && flag != 18) { Motor_SetAllSpeed(speed*0.3, speed);/* Serial.println("LLL");*/ flag = 18; }


}


//�ߵ�ָ����������⵽ֵ
void Motor_Sensor(int HuiduId, int speed1, int speed2)
{

	int flagval = Huidu_LineValues[HuiduId - 1];
	if (HuiduId == 3)flagval += 100;

	Motor_SetAllSpeed(speed1, speed2);
	while (1)
	{ 
		Motor_Go();
		if (Huidu_Read(HuiduId) <flagval) { Motor_Stop(); break; }
	}
}
	
//��⵽·�ھ�ֹͣ
//speed:�ٶȣ���λcm/s
void ST(int speed) //��·��ֹͣ
{
	//int t = millis();
	flag = 0;
	while (1)
	{
		
	
		Motor_Go();
	
		if (Huidu_IsLine(1) || Huidu_IsLine(5)) {/* Serial.println("lukou"); */Beep(); Motor_Stop(); break; }
		else go_Line(speed);

	}
	flag = 0;;
	
}
//ST��ͣ��
void ST2(int speed) //��·��ֹͣ
{

	flag = 0;
	while (1)
	{
	

		Motor_Go();
	
		if (Huidu_IsLine(1) || Huidu_IsLine(5)) {/* Serial.println("lukou"); */BeepT(); Motor_Stop(); break; }
		else go_Line(speed);
		
	}
	flag = 0;;

}


//ֹͣ�������ɵ���ST
void ST(int speed,int sensorvalue) //��·��ֹͣ
{
	//int t = millis();
	flag = 0;
	while (1)
	{
		//HD();

		Motor_Go();
		/*if(millis()-t>200){*/
		if (Huidu_Read(1)<sensorvalue || Huidu_Read(1)<sensorvalue) {/* Serial.println("lukou"); */Beep(); Motor_Stop(); break; }
		else go_Line(speed);
		/*	t = millis();
		}*/
	}
	flag = 0;;

}


//��⵽·��ǰ��ָ��ʱ��
//speed:�ٶȣ���λcm/s

void GT(int speed, int t) //��·��ֱ�� 
{
	ST2(speed);
	//delay(200);
	
	Motor_GoTime(t , Turn_Speed, Turn_Speed);

}

//��⵽·��ǰ��ָ��ʱ��
//speed:�ٶȣ���λcm/s
//gong_speed :�����ٶ�
void GT(int speed, int t, int gong_speed) //��·��ֱ�� 
{
	flag = 0;
	while (1)
	{
	

		Motor_Go();
		/*if(millis()-t>200){*/
		if (Huidu_IsLine(1) || Huidu_IsLine(5)) { 
			/*Serial.println("lukou");*/ Beep();
			Motor_SetAllSpeed(gong_speed, gong_speed);
			unsigned long now = millis();
			while (millis() - now<t)
			{
				Motor_Go();
			}
			
			break;
		
		}
		else go_Line(speed);
		/*	t = millis();
		}*/
	}
	flag = 0;;
	

	

}

void LT(int speed,int t) //��·����ת
{
    ST2(speed);
	//delay(200);
	Motor_GoTime(t , Turn_Speed, Turn_Speed);
	Motor_GoTime(500, -20, 20);
	Motor_Sensor(3, -Forward_Speed, Forward_Speed);

//msleep(50);
}


void RT(int speed, int t) //��·����ת
{
	ST2(speed);
	delay(200);
	Motor_GoTime(t , Turn_Speed, Turn_Speed);
	Motor_GoTime(500, 20, -20);
	Motor_Sensor(3, Forward_Speed, -Forward_Speed);
}

//����ʱ�޸���RT
void RT(int speed, int t,int outtime) //��·����ת
{
	ST2(speed);
	delay(200);
	Motor_GoTime(t, Turn_Speed, Turn_Speed);
	Motor_GoTime(500, 20, -20);
	Motor_Sensor(3, Forward_Speed, -Forward_Speed,outtime);
}