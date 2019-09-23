#include "Modules.h"
#include "IncludeList.h"


#pragma region 基本道路

void Round_Left()
{
	ST(Forward_Speed);
	delay(200);
	Motor_GoTime(300, Turn_Speed, Turn_Speed);
	Motor_GoTime(300, -25, 25);
	Huidu_LineValues[3] += 100;
	Motor_Sensor(3, -Turn_Speed, Turn_Speed);
	Huidu_LineValues[3] -= 100;
	GT(Forward_Speed, 550);
	Motor_Sensor(3, -Forward_Speed, Forward_Speed);



}
void Round_Right()
{
	ST(Forward_Speed);
	delay(200);
	Motor_GoTime(200, Turn_Speed, Turn_Speed);
	Motor_GoTime(300, 25, -25);
	Huidu_LineValues[3] += 100;
	Motor_Sensor(3, Turn_Speed, -Turn_Speed);
	Huidu_LineValues[3] -= 100;
	GT(Forward_Speed, 550);
	Motor_Sensor(3, Forward_Speed, -Forward_Speed);

	/*GT(Forward_Speed, 400);
	Motor_GoTime(550 , Turn_Speed, -Turn_Speed);
	Motor_Sensor(1, Forward_Speed, Forward_Speed);
	RT(Forward_Speed,)*/
}

void Ling_Left() {
	LT(Forward_Speed, 800);
	LT(Forward_Speed, 1350);


}

void Ling_Right	() {
	RT(Forward_Speed, 800);
	RT(Forward_Speed, 650);


}

void M_L1()
{
	while (Time_TakeTime(500))
	{
		go_Line(Forward_Speed);
	}
	Motor_Sensor(1, Forward_Speed, Forward_Speed);
	Motor_GoTime(200,Forward_Speed, Forward_Speed );
	
	Motor_Sensor(3, -Turn_Speed, Turn_Speed);

	//Motor_GoTime(1000, Turn_Speed, Turn_Speed);
	//RT(Forward_Speed, 500);

	LT(Forward_Speed, 1200);

}

void M_R2() {
	RT(Forward_Speed, 300);
	while (Time_TakeTime(500))
	{
		go_Line(Forward_Speed);
	}
	Motor_Sensor(5, Forward_Speed, Forward_Speed);
	Motor_GoTime(350, Turn_Speed, Turn_Speed);
	Motor_Sensor(3, Forward_Speed, -Forward_Speed);

//	GT(Forward_Speed, 100);
	//Motor_Sensor(3, Turn_Speed, -Turn_Speed);

}
void M_L2(){
	while (Time_TakeTime(500))
	{
		go_Line(Forward_Speed);
	}
	Motor_Sensor(5, Forward_Speed, Forward_Speed);
	Motor_GoTime(500, Turn_Speed, Turn_Speed);
	LT(Forward_Speed, 800);
	GT(Forward_Speed, 400);

}
void M_R3() {
	ST(Forward_Speed, 600);
	Motor_GoTime(420, Turn_Speed, Turn_Speed);
	//GT(Forward_Speed, 400);
	RT(Forward_Speed, 700);
	GT(Forward_Speed, 400);
}
void M_L3()
{
	LT(Forward_Speed, 300);
	while (Time_TakeTime(500))
	{
		go_Line(Forward_Speed);
	}
	Motor_Sensor(1, Forward_Speed, Forward_Speed);
	Motor_GoTime(500, Turn_Speed, Turn_Speed);
	Motor_Sensor(3, -Forward_Speed, Forward_Speed);
//	GT(Forward_Speed, 550);

}
void M_R4() {
	while (Time_TakeTime(500))
	{
		go_Line(Forward_Speed);
	}
	Motor_Sensor(5, Forward_Speed, Forward_Speed);
	Motor_Sensor(3, Turn_Speed, -Turn_Speed);

//Motor_GoTime(1000, Turn_Speed, Turn_Speed);
	//RT(Forward_Speed, 500);
	
	RT(Forward_Speed, 1100);
}
void Yingchong() {
	GT(Turn_Speed, 400);
	Motor_GoTime(2000, Turn_Speed, Turn_Speed);
	Motor_GoTime(600,- Forward_Speed,Forward_Speed);
	Motor_GoTime(1800, Turn_Speed, Turn_Speed);
}
void LVFANGGE() {
	GT(Forward_Speed, 300);
	LT(Turn_Speed, 800);
	GT(Forward_Speed, 300);
}
#pragma endregion


#pragma region 任务

void Start()
{
	Motor_GoTime(670, -Turn_Speed, Turn_Speed);
	Motor_GoTime(1050, Turn_Speed, Turn_Speed);
	
}


void Zuoshang()
{
	LT(Forward_Speed, 700);
	RT(Forward_Speed, 500);
	ST2(Forward_Speed);
	delay(200);
	Motor_GoTime(500, Turn_Speed, Turn_Speed - 5);
	Motor_GoTime(500, 20, -20);
	Motor_Sensor(3, Forward_Speed, -Forward_Speed);
	RT(Forward_Speed, 850);
	LT(Forward_Speed, 700);
	/*RT(Forward_Speed, 700);
	LT(Forward_Speed, 700);
*/
	ST(Forward_Speed);
	Motor_GoTime(600, Forward_Speed, Forward_Speed);

}
void Youshang()
{
	GT(Forward_Speed, 2200);
	

	//Motor_Sensor(3, Forward_Speed,- Forward_Speed);
	Motor_GoTime(600, Forward_Speed, -Forward_Speed);
	Motor_GoTime(100, Turn_Speed, Turn_Speed);
	GT(Forward_Speed, 400);
	
}
void NB()
{
	LT(Forward_Speed, 800);
	RT(Forward_Speed, 500);
	GT(Forward_Speed,400);
	GT(Forward_Speed, 400);
	Motor_GoTime(600, Turn_Speed, -Turn_Speed);
	Motor_GoTime(800, Turn_Speed, Turn_Speed);
	Motor_GoTime(200, Turn_Speed, -Turn_Speed);
	RT(Forward_Speed, 800);
	LT(Forward_Speed, 800);
	//Motor_GoTime(500, 20, -20);
	//Motor_Sensor(3, Forward_Speed, -Forward_Speed);


}



void Youxia()
{

	LT(Forward_Speed, 700);
	RT(Forward_Speed, 500);
	int v = Huidu_LineValues[4];
	Huidu_LineValues[4] = 1;
	ST2(Forward_Speed);
	delay(200);
	Motor_GoTime(500, Turn_Speed, Turn_Speed - 5);
	Motor_GoTime(500, 20, -20);
	Motor_Sensor(3, Forward_Speed, -Forward_Speed);
	RT(Forward_Speed, 400);

	Huidu_LineValues[4] = v;

	LT(Forward_Speed, 700);

}
//垃圾分类
void Trash_Judgement_Left() {
	ST(Forward_Speed);
	Goline_Adjust();
	Motor_GoTime(400, -Turn_Speed, -Turn_Speed);
	ST(Turn_Speed);
	Goline_Adjust();
	Arm_Go(2, 15); delay(20);

	Arm_Go(3, 40); delay(20);

	Arm_Go(4, 89); delay(20);

	Arm_Go(3, 20); delay(20);

	Arm_Go(2, 52); delay(20);

	Arm_Go(4, 103); delay(1000);

	Arm_Go(1, 53); delay(20);

	
	//(1, 50);
	//delay(400);
	Arm_Go(3,40);
	delay(20);
	Arm_Go(2, 20);
	delay(20);
	
	Arm_Go(3, 30);
	delay(20);
	
	Arm_Go(4, 140);
	delay(1000);
	Arm_Go(2, 15);
	delay(20);
	Arm_Go(1, 0);
	
	delay(20);
	
	Arm_Go(4, 115); delay(20);

	Arm_Go(3, 3); delay(20);

	Arm_Go(2, 31); delay(20);

	Arm_Go(4, 103); delay(1000);
	Arm_Go(1, 53);
	delay(20);
	Arm_Go(3, 30);
	delay(20);
	Arm_Go(2, 20);
	delay(20);
	
	Arm_Go(4, 65);
	delay(1000);
	Arm_Go(2, 15);
	delay(20);
	Arm_Go(1, 0);
	delay(20);
	
	Arm_Go(4, 108);
	delay(20);
	Arm_Reset();

	Motor_GoTime(300, Turn_Speed, Turn_Speed);
	//GT(Forward_Speed, 20);
}
void Trash_Judgement_Right() {
	ST(Forward_Speed);
	Goline_Adjust();
	Motor_GoTime(400, -Turn_Speed, -Turn_Speed);
	ST(Turn_Speed);
	Goline_Adjust();
	Arm_Go(2, 15); delay(20);

	Arm_Go(3, 40); delay(20);

	Arm_Go(4, 89); delay(20);

	Arm_Go(3, 20); delay(20);

	Arm_Go(2, 52); delay(20);

	Arm_Go(4, 103); delay(1000);

	Arm_Go(1, 53); delay(20);


	//(1, 50);
	//delay(400);
	Arm_Go(3, 40);
	delay(20);
	Arm_Go(2, 20);
	delay(20);

	Arm_Go(3, 30);
	delay(20);

	Arm_Go(4, 65);
	delay(1000);
	Arm_Go(2, 15);
	delay(20);
	Arm_Go(1, 0);
	delay(20);

	Arm_Go(4, 115); delay(20);

	Arm_Go(3, 3); delay(20);

	Arm_Go(2, 31); delay(20);

	Arm_Go(4, 103); delay(1000);
	Arm_Go(1, 53);
	delay(20);
	Arm_Go(3, 30);
	delay(20);
	Arm_Go(2, 20);
	delay(20);

	Arm_Go(4, 140);
	delay(1000);
	Arm_Go(2, 15);
	delay(20);
	Arm_Go(1, 0);
	delay(20);

	Arm_Go(4, 108);
	delay(20);
	Arm_Reset();

	Motor_GoTime(300, Turn_Speed, Turn_Speed);
	//GT(Forward_Speed, 20);
}


void BigDad_Fix_Right(){
	GT(Forward_Speed, 300);
	ST(Forward_Speed);
	Goline_Adjust();
	Arm_Go(2, 15);
	delay(20);
	Arm_Go(4, 40);
	delay(300);
	Arm_Go(1, 27);
	delay(20);
	Arm_Go(3, 30);
	delay(200);
	Arm_Go(2, 60);
	delay(200);
	Arm_Go(1, 12);
	delay(20);
	Arm_Go(2, 65);
	delay(200);
	Arm_Go(3, 25);
	delay(200);
	Arm_Go(2, 68);
	delay(200);
	Arm_Go(3, 20);
	delay(200);
	Arm_Go(2, 71);
	delay(200);
	Arm_Go(1, 52);
	delay(20);
	Arm_Go(3, 28);
	delay(20);
	Arm_Go(2, 59);
	delay(20);
	Arm_Go(3, 35);
	delay(20);
	Arm_Go(2, 54);
	delay(20);
	Arm_Go(2, 0);
	delay(20);
	Arm_Go(3, 110);
	delay(20);
	
	Arm_Go(4, 67);
	delay(300);
	Arm_Go(2, 15);
	delay(20);
	Arm_Go(1, 0);
	delay(20);
	Arm_Go(4, 108);
	delay(20);
	Arm_Reset();
	//Motor_GoTime(300, Turn_Speed, Turn_Speed);
}
void BigDad_Fix_Left() {
	GT(Forward_Speed, 300);
	ST(Forward_Speed);
	Goline_Adjust();
	Arm_Go(2, 15);
	delay(20);
	Arm_Go(4, 160);
	delay(300);
	Arm_Go(1, 27);
	delay(20);
	Arm_Go(3, 30);
	delay(200);
	Arm_Go(2, 60);
	delay(200);
	Arm_Go(1, 12);
	delay(20);
	Arm_Go(2, 65);
	delay(200);
	Arm_Go(3, 25);
	delay(200);
	Arm_Go(2, 68);
	delay(200);
	Arm_Go(3, 20);
	delay(200);
	Arm_Go(2, 71);
	delay(200);
	Arm_Go(1, 52);
	delay(20);
	Arm_Go(3, 28);
	delay(20);
	Arm_Go(2, 59);
	delay(20);
	Arm_Go(3, 35);
	delay(20);
	Arm_Go(2, 54);
	delay(20);
	Arm_Go(2, 0);
	delay(20);
	Arm_Go(3, 110);
	delay(20);
	
	Arm_Go(4, 64);
	delay(300);
	Arm_Go(2, 15);
	delay(20);
	Arm_Go(1, 0);
	delay(20);
	Arm_Go(4, 108);
	delay(20);
	Arm_Reset();
	//Motor_GoTime(300, Turn_Speed, Turn_Speed);
}

void Plant_Trees_right() {
	ST(Forward_Speed);
	Motor_GoTime(400, -Turn_Speed, -Turn_Speed);

	ST(Turn_Speed);
	/*Goline_Adjust();*/
	Arm_Go(2, 15);
	delay(200);
	Arm_Go(3, 23);
	delay(200);

	Arm_Go(4, 103);

	delay(200);
	Arm_Go(2, 32);
	delay(10);
	Arm_Go(2, 34);
	delay(40);
	//Arm_Go(2, 39);
	//delay( 20);
	Arm_Go(3, 22);
	delay(40);
	Arm_Go(2, 34);
	delay(40);
	Arm_Go(3, 21);
	delay(30);
	Arm_Go(2, 34);
	delay(80);
	/*Arm_Go(2, 40);
	delay(800);*/
	//	Arm_Go(2, 41);
	//delay( 20);
	/*Arm_Go(2, 42);
	delay( 20);*/

	Arm_Go(3, 20);
	delay(40);
	Arm_Go(2, 36);
	delay(80);

	Arm_Go(3, 19);
	delay(30);
	Arm_Go(3, 18);
	delay(20);


	Arm_Go(2, 40);
	delay(20);
	Arm_Go(1, 57);
	delay(20);


	Arm_Go(2, 20);
	delay(20);
	Arm_Go(3, 15);
	delay(20);
	Arm_Go(4, 68,35);
	delay(500);
	Arm_Go(3, 4);
	delay(400);
	/*Arm_Go(2, 28); delay(300);*/
	Arm_Go(1, 0);
	delay(40);
	Arm_Go(4, 108);
	delay(300);
	Arm_Reset();
	Motor_GoTime(300, Turn_Speed, Turn_Speed);
}
void Plant_Trees_left() {
	ST(Forward_Speed);
	Motor_GoTime(400, -Turn_Speed, -Turn_Speed);

	ST(Turn_Speed);
	/*Goline_Adjust();*/
	Arm_Go(2, 15);
	delay(200);
	Arm_Go(3, 23);
	delay(200);

	Arm_Go(4, 103);

	delay(200);
	Arm_Go(2, 32 );
	delay(10);
	Arm_Go(2, 34);
	delay(40);
	//Arm_Go(2, 39);
	//delay( 20);
	Arm_Go(3, 22);
	delay(40);
	Arm_Go(2, 34);
	delay(40);
	Arm_Go(3, 21);
	delay(30);
	Arm_Go(2, 34);
	delay(80);
	/*Arm_Go(2, 40);
	delay(800);*/
	//	Arm_Go(2, 41);
	//delay( 20);
	/*Arm_Go(2, 42);
	delay( 20);*/

	Arm_Go(3, 20);
	delay(40);
	Arm_Go(2, 36);
	delay(80);

	Arm_Go(3, 19);
	delay(30);
	Arm_Go(3, 18);
	delay(20);


	Arm_Go(2, 40);
	delay(20);
	Arm_Go(1, 57);
	delay(20);
	

	
	Arm_Go(3, 15);
	delay( 20);
	Arm_Go(2, 25);
	delay(20);
	Arm_Go(4, 137,35);
	delay(800);
	Arm_Go(3,5);
	delay(400);
	/*Arm_Go(2, 28); delay(300);*/
	Arm_Go(1, 0);
	delay(40);
	Arm_Go(4, 108);
	delay(300);
	Arm_Reset();
Motor_GoTime(300, Turn_Speed, Turn_Speed);
	
}


void Hit_PoliceClock_Right()
{
	ST(Forward_Speed);
	Motor_GoTime(400, -Turn_Speed, -Turn_Speed);
	delay(200);
	ST(Turn_Speed);
	Goline_Adjust();
	Motor_GoTime(70, Turn_Speed, Turn_Speed);
	delay(200);
	Arm_Go(2,20);
	delay(20);
	Arm_Go(3, 50);
	delay(20);
	Arm_Go(2, 35);
	delay( 20);
	Arm_Go(4, 72);
	delay( 200);
	Arm_Go(3, 0);
	delay( 200);
	Arm_Go(2, 35);
	delay( 200);
	Arm_Go(1, 57);
	delay( 20);
	Arm_Go(3, 62);
	delay( 20);
	Arm_Go(2,3 );
	delay( 20);
	Motor_GoTime(400, Turn_Speed, Turn_Speed);
	ST(Forward_Speed);
	Arm_Go(4, 65);delay(200);
	Arm_Go(4, 50);delay( 20);
	Arm_Go(4, 65);delay( 500);
	Arm_Go(4, 50);delay( 20);
	Arm_Go(4, 65);delay( 500);
	Arm_Go(4, 50);delay( 20);
	Arm_Go(4, 65);delay(500);
	Arm_Go(4, 50);delay(20);
	Arm_Go(4, 60); delay(500);
	Arm_Go(1, 0);
	delay(200);
	Arm_Go(4, 108);
	delay(200);

	Arm_Reset();




}
void Hit_PoliceClock_Left()
{
	ST(Forward_Speed);
	Motor_GoTime(400, -Turn_Speed, -Turn_Speed);
	delay(200);
	ST(Turn_Speed);
	Goline_Adjust();
	
	Motor_GoTime(70, Turn_Speed, Turn_Speed);
	Arm_Go(2, 20);
	delay(200);
	Arm_Go(3, 50);
	delay(200);
	Arm_Go(2, 35);
	delay( 20);
	Arm_Go(4, 130);
	delay( 200);
	Arm_Go(3, 0);
	delay( 200);
	Arm_Go(2, 33);
	delay( 200);
	Arm_Go(1, 57);
	delay( 20);
	Arm_Go(3, 66);
	delay(20);
	Arm_Go(2, 0);
	delay(20);
	Motor_GoTime(200, Turn_Speed, Turn_Speed);
	Motor_GoTime(200, Turn_Speed, Turn_Speed);
	ST(Forward_Speed);
	
	Arm_Go(4, 158);delay( 20);
	Arm_Go(4, 140);delay( 400);
	
	Arm_Go(4, 158);delay( 20);
	Arm_Go(4, 140);delay( 400);
	
	Arm_Go(4, 158);delay( 20);
	Arm_Go(4, 140); delay(400);
	
	Arm_Go(4, 158); delay(20);
	Arm_Go(4, 150); delay(800);
	Arm_Go(1, 0);
	delay(200);
	Arm_Go(4, 108);
	delay(200);
	
	Arm_Reset();





}

void Transport_Lead_Right() {
	Beep();
	ST(Forward_Speed);
	Motor_GoTime(400, -Turn_Speed, -Turn_Speed);
	delay(500);
	ST(Turn_Speed);
	//delay(200);

	Goline_Adjust();
	Dianzhen_Shownum(0);
	Motor_GoTime(450, Turn_Speed, Turn_Speed);
	//Arm_Go(2, 15); delay( 20);

	//Arm_Go(4, 90); delay( 20);

	//Arm_Go(3, 40); delay( 200);

	//Arm_Go(2, 38); delay( 200);

	//Arm_Go(4, 55); delay(100);
	//Arm_Go(3, 37); delay(200);

	//Arm_Go(2, 43); delay(200);
	//Arm_Go(3, 32); delay(200);
	//Arm_Go(1, 52); delay(20);
	//Arm_Go(2, 40); delay(20);

	//Arm_Go(4, 42); delay(1000);
	//Arm_Go(2, 43); delay(600);
	//Arm_Go(1, 0); delay(20);
	///*Arm_Go(4, 65); delay(20);*/
	////Arm_Go(1, 52); delay(20);
	//Dianzhen_Shownum(1);
	
	//Arm_Go(4, 80); delay(20);
	///*Arm_Go(3, 27); delay(20);

	//
	//
	//Arm_Go(2, 53); delay( 100);

	//Arm_Go(4, 102,25); delay(1000);
	//
	//Arm_Go(1, 55); delay(20);
	//Arm_Go(2, 48); delay(20);
	//Arm_Go(4, 65,25); delay(1000);
	//Arm_Go(2, 53); delay(500);
	//Arm_Go(1, 0); delay(20);*/

	Arm_Go(2, 15); delay(20);

	Arm_Go(4, 102); delay(100);

	Arm_Go(3, 40); delay(200);

	Arm_Go(2, 40); delay(200);
	Arm_Go(2, 45); delay(200);
	Arm_Go(3, 36); delay(200);
	Arm_Go(2, 50); delay(200);
	Arm_Go(3, 30); delay(200);
	/*Arm_Go(4, 102); delay(100);*/
	
	Arm_Go(1, 55); delay(20);
	Arm_Go(2, 47); delay(20);

	Arm_Go(4, 65); delay(1000);
	Arm_Go(2, 52); delay(600);
	Arm_Go(1, 0); delay(20);
	Dianzhen_Shownum(1);
	Beep();
	Arm_Go(4, 108); delay(300);
	/*Arm_Go(4, 108); delay(300);
	Arm_Reset();
	
	Arm_Go(2, 15); delay(20);
	Arm_Go(4, 136,100); delay(300);
	Arm_Go(3, 5,30); delay(20);
	

	Arm_Go(1, 57); delay(20);
	Arm_Go(2, 12); delay(20);
	Arm_Go(4, 145); delay(20);
	
	Arm_Go(2, 16,15); delay(500);
	Arm_Go(1, 0); delay(20);

	Dianzhen_Shownum(3);
	Beep(); Beep(); Beep();

	Arm_Go(4, 108); delay(20);*/

	Arm_Reset();

	



}
void Transport_Lead_Left() {
	ST(Forward_Speed);
	Motor_GoTime(400, -Turn_Speed, -Turn_Speed);
	delay(200);
		ST(Turn_Speed);
	//delay(200);
		Goline_Adjust();
		Dianzhen_Shownum(0);
		Motor_GoTime(450, Turn_Speed, Turn_Speed);
	Led_Clear(); Beep();
	Arm_Go(2, 15); delay( 20);
	Arm_Go(4, 163); delay(200);
	

	Arm_Go(3, 25); delay( 20);

	Arm_Go(2, 50); delay( 20);
	Arm_Go(4, 152); delay(500);
	/*Arm_Go(4, 144); delay(20);*/
	
	Arm_Go(1, 55); delay(200);
	Arm_Go(2, 48); delay(500);
	Arm_Go(4, 165); delay(400);
	Arm_Go(2, 50); delay(30);
	Arm_Go(1, 0); delay(20);
	Dianzhen_Shownum(1);
	Beep();

	Arm_Go(3, 25); delay(20);

	Arm_Go(4, 136); delay( 20);

	Arm_Go(2, 51); delay( 20);

	Arm_Go(4, 103); delay(500);
	
	Arm_Go(1, 55); delay(200);
	Arm_Go(2, 48); delay(20);
	Arm_Go(4, 139); delay(500);
	Arm_Go(2, 51); delay(300);
	Arm_Go(1, 0); delay(20);
	Dianzhen_Shownum(2);
	Beep();

	Arm_Go(4, 108); delay(20);

	Arm_Go(2, 22); delay(30);

	Arm_Go(3, 4); delay(20);

	Arm_Go(4, 73); delay(500);

	Arm_Go(1, 55); delay(500);
	Arm_Go(2, 21); delay(300);
	Arm_Go(4, 65); delay(500);
	
	Arm_Go(2, 23); delay(150);
	Arm_Go(1, 0); delay(200);
	Arm_Go(2, 24); delay(20);
	Dianzhen_Shownum(3);
	Beep();
	Arm_Go(4, 81); delay(20);
	/*Arm_Go(1, 52); delay(100);*/
	Arm_Go(4, 108); delay(20);

	Arm_Reset();


	



}


void Fire_Savement_Left() {
	//倒退回线
	ST(Forward_Speed);
	Motor_GoTime(400, -Turn_Speed, -Turn_Speed);
	ST(Turn_Speed);
	Goline_Adjust();
	Arm_Go(2, 15);
	delay(500);
	Arm_Go(3, 23);
	delay( 300);

	Arm_Go(4, 104);

	delay( 200);
	Arm_Go(2, 32,30);
	delay( 1000);
	Arm_Go(2, 34);
	delay(400);
	//Arm_Go(2, 39);
	//delay( 20);
	Arm_Go(3, 22);
	delay(400);
	Arm_Go(2, 34);
	delay(400);
	Arm_Go(3, 21);
	delay(300);
	Arm_Go(2, 34,30);
	delay(800);
	/*Arm_Go(2, 40);
	delay(800);*/
	//	Arm_Go(2, 41);
	//delay( 20);
	/*Arm_Go(2, 42);
	delay( 20);*/
	
	Arm_Go(3, 20);
	delay(400);
	Arm_Go(2, 36);
	delay(800);
	
	Arm_Go(3, 19);
	delay(300);
	Arm_Go(3, 18);
	delay(200);
	

	Arm_Go(2, 40);
	delay(20);
	Arm_Go(1, 30);
	delay( 20);
	Arm_Go(3, 40);
	delay(20);
	Arm_Go(4, 91);
	delay(300);
	Arm_Go(2, 25);
	delay(20);
	Arm_Go(3, 100);
	delay(20);
	Arm_Go(1, 0);




	Arm_Go(2, 15);
	delay( 20);
	Arm_Go(4, 138);
	delay( 400);
	Arm_Go(1, 20);
	delay(20);
	Arm_Go(3, 13);
	delay( 20);
	Arm_Go(2, 30);
	delay(200);
	Arm_Go(2, 35);
	delay(200);
	Arm_Go(2, 40);
	delay( 20);
	Arm_Go(2, 45);
	delay(20);
	Arm_Go(1, 65);
	delay( 20);
	Arm_Go(3, 35);
	delay( 20);
	Arm_Go(2, 30);
	delay( 20);
	/*Arm_Go(4, 107);
	delay( 20);
	Arm_Go(2,35 );
	delay( 20);
	Arm_Go(2, 39);
	delay( 20);
	Arm_Go(3, 30);
	delay( 20);
	Arm_Go(3, 28);
	delay( 20);
	Arm_Go(1, 0);
	delay( 20);
	Arm_Reset();*/
	Arm_Go(4, 102);
	delay(1000);
	Arm_Go(2, 35);
	delay(20);
	Arm_Go(2, 39);
	delay(600);
	Arm_Go(3, 28);
	delay(600);
	Arm_Go(2, 42);
	delay(600);

	Arm_Go(1, 0);
	delay(20);
	Arm_Reset();
//	Motor_GoTime(300, Turn_Speed, Turn_Speed);

}
void Fire_Savement_Right() {
	/*GT(Forward_Speed, 200);

	Arm_Go(2, 15);
	delay(400);
	Arm_Go(3, 30);
	delay(800);
	Arm_Go(2, 43);
	delay(400);
	Arm_Go(3, 27);
	delay(400);
	Arm_Go(2, 47);
	delay(400);
	Arm_Go(1, 25);
	delay(400);
	Arm_Go(2, 15);
	delay(400);
	Arm_Go(3, 85);
	delay(400);
	Arm_Go(1, 0);
	delay(400);
	Arm_Go(3, 70);
	delay(400);
	Arm_Go(4, 80);
	delay(400);
	Arm_Go(3, 18);
	delay(400);
	Arm_Go(2, 45);
	delay(400);
	Arm_Go(1, 58);
	delay(400);
	Arm_Go(3, 37);
	delay(400);
	Arm_Go(2, 20);
	delay(400);
	Arm_Go(4, 106);
	delay(400);
	Arm_Go(2, 45);
	delay(400);

	Arm_Go(3, 30);
	delay(400);
	Arm_Go(1, 0);
	delay(400);*/
	ST(Forward_Speed);
	Motor_GoTime(400, -Turn_Speed, -Turn_Speed);
	ST(Turn_Speed);
	Goline_Adjust();
	Arm_Go(2, 15);
	delay(500);
	Arm_Go(4, 103);

	delay(200);
	Arm_Go(3, 23);
	delay(300);

	Arm_Go(4, 101);

	delay(200);
	Arm_Go(2, 32,30);
	delay(1000);
	Arm_Go(2, 34);
	delay(400);
	//Arm_Go(2, 39);
	//delay( 20);
	Arm_Go(3, 22);
	delay(400);
	Arm_Go(2, 34);
	delay(400);
	Arm_Go(3, 21);
	delay(300);
	Arm_Go(2, 36,35);
	delay(800);
	/*Arm_Go(2, 40);
	delay(800);*/
	//	Arm_Go(2, 41);
	//delay( 20);
	/*Arm_Go(2, 42);
	delay( 20);*/

	Arm_Go(3, 20);
	delay(400);
	Arm_Go(2, 37);
	delay(800);

	Arm_Go(3, 19);
	delay(300);
	Arm_Go(3, 18);
	delay(200);


	Arm_Go(2, 40);
	delay(20);
	Arm_Go(1, 30);
	delay(20);
	Arm_Go(3, 40);
	delay(20);
	Arm_Go(4, 91);
	delay(300);
	Arm_Go(2, 25);
	delay(20);
	Arm_Go(3, 100);
	delay(20);
	Arm_Go(1, 0);






	
	Arm_Go(2, 15);
	delay(20);
	Arm_Go(4, 68);
	delay(400);
	Arm_Go(1, 20);
	delay(20);
	Arm_Go(3, 13);
	delay(20);
	Arm_Go(2, 30);
	delay(200);
	Arm_Go(2, 35);
	delay(200);
	Arm_Go(2, 40);
	delay(20);
	Arm_Go(2, 45);
	delay(20);
	Arm_Go(1, 65);
	delay(20);
	Arm_Go(3, 35);
	delay(20);
	Arm_Go(2, 30);
	delay(20);
	/*Arm_Go(4, 107);
	delay( 20);
	Arm_Go(2,35 );
	delay( 20);
	Arm_Go(2, 39);
	delay( 20);
	Arm_Go(3, 30);
	delay( 20);
	Arm_Go(3, 28);
	delay( 20);
	Arm_Go(1, 0);
	delay( 20);
	Arm_Reset();*/
	Arm_Go(4, 101);
	delay(1000);
	Arm_Go(2, 35);
	delay(20);
	Arm_Go(2, 39);
	delay(600);
	Arm_Go(3, 28);
	delay(600);
	Arm_Go(2, 42);
	delay(600);

	Arm_Go(1, 0);
	delay(20);
	Arm_Reset();
	//	Motor_GoTime(300, Turn_Speed, Turn_Speed);

}

void Naguoqu() {

	ST(Forward_Speed);
	Motor_GoTime(400, -Turn_Speed, -Turn_Speed);
	delay(200);
	ST(Turn_Speed);
	//Goline_Adjust();
	Arm_Go(2, 26); delay(20);

	Arm_Go(4, 124); delay( 20);

	Arm_Go(1, 55); delay( 20);

	Arm_Go(2, 15); delay(20);

	Arm_Go(4, 101); delay( 200);

	Arm_Go(3, 4); delay( 20);

	Arm_Go(2, 42); delay( 20);

	Arm_Go(1, 0); delay( 20);

	Arm_Go(4, 120); delay( 20);

	Arm_Go(2, 0); delay( 20);

	Arm_Go(3, 85); delay( 20);
	
	Arm_Reset();
	Motor_GoTime(800, Turn_Speed, Turn_Speed);
	Motor_GoTime(2400, Turn_Speed, -Turn_Speed);
	Motor_Sensor(3, Forward_Speed, -Forward_Speed);
}
void Nahuijia() {
	ST(Forward_Speed);
//	while (Time_TakeTime(350))
//	{
//		go_line_back(-Forward_Speed);
//	}
//	delay(200);
//	ST(Turn_Speed);
////	Goline_Adjust();
	Arm_Go(2, 15); delay( 20);

	Arm_Go(4, 120); delay( 20);

	Arm_Go(3, 15); delay( 20);

	Arm_Go(2, 56); delay(20);

	Arm_Go(4, 101); delay(500);

	Arm_Go(1, 53); delay( 20);

	Arm_Go(3, 30); delay( 20);

	Arm_Go(2, 0); delay( 20);

	Arm_Go(3, 115); delay(20);

	Arm_Go(4, 122); delay(20);

	Arm_Go(2, 23); delay( 20);

	Arm_Go(1, 0); delay(300);

	Arm_Go(4, 101); delay( 20);
	Arm_Reset();
	/*Motor_GoTime(800, Turn_Speed, Turn_Speed);
	Motor_GoTime(2400, Turn_Speed, -Turn_Speed);
	Motor_Sensor(3, Forward_Speed, -Forward_Speed);*/
	
}

void Test_Values() 
{
	int mins[5] = { 1000,1000,1000,1000,1000 };
	int maxs[5] = { 0,0,0,0,0 };
	Motor_SetAllSpeed(10, 10);
	int t = millis();
	while (millis()-t<=5000)
	{
		Motor_Go();
		if (millis() - t >= 2000) { Motor_SetAllSpeed(10, -15); }
		if (millis() - t >= 2500) { Motor_SetAllSpeed(-10, -10); }
		for (int i = 0; i < 5; i++)
		{
			int v = Huidu_Read(i + 1);
			if (mins[i] > v)mins[i] = v;
			if (maxs[i] < v)maxs[i] = v;

		}
	}
	Motor_Stop();
	for (int i = 0; i < 10; i++)
	{
		char str[100];
		sprintf(str, "123%%%%%d%%%%%d%%%%%d%%%%%d%%%%%d%%%%4", mins[0], mins[1], mins[2], mins[3], mins[4]);
		Serial.println(str);
		delay(5000);
		sprintf(str, "123%%%%%d%%%%%d%%%%%d%%%%%d%%%%%d%%%%4", maxs[0], maxs[1], maxs[2], maxs[3], maxs[4]);
	
		Serial.println(str);
		delay(5000);
	}
}
#pragma endregion

