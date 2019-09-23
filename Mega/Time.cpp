#include "Time.h"
#include "IncludeList.h"
unsigned long   lasttime = 0;

boolean isstart = false;

bool Time_TakeTime(int time)

{
	if (!isstart )
	{
		lasttime = millis();
		isstart = true;
		return true;
	}
	else if (millis() - lasttime < time)
	{
		return true;

	}
	else
	{
		isstart = false;

		return false;
	}
	


}