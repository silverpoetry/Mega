#include "Beeper.h"
void Beeper_Init()
{

	pinMode(Beeper_Pin, OUTPUT);
	digitalWrite(Beeper_Pin, LOW);
}
void Beep()
{
	digitalWrite(Beeper_Pin, HIGH);
	delay(100);
	digitalWrite(Beeper_Pin, LOW);
}

bool beepstart = false;
unsigned long lastttime;
void BeepT()
{
	digitalWrite(Beeper_Pin, HIGH);
	beepstart = true;
	lastttime = millis();
//digitalWrite(Beeper_Pin, LOW);
}
void unBeep()
{


	if (beepstart)
	{

		if (millis()-lastttime >=100)
		{
			digitalWrite(Beeper_Pin, LOW);
			beepstart = false;
		}
		else
		{
		//	lastttime = millis();
		}

	
	}
}