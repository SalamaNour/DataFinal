#include "Healer.h"
#include <fstream>
#include <iostream>
#include <string>



Healer::Healer(int id, int arrTime, int type,double H,double P,int Reloadtime,double speed):Enemy(id,arrTime)
{
	SetType(type);
	SetHealth(H);
	SetPower(P);
	SetReloadTime(Reloadtime);
	SetSpeed(speed);
	OriginalHealth=H;

}

Healer::Healer(int id, int arrTime):Enemy(id,arrTime)
{
}


Healer::~Healer()
{
}

void Healer::Move()
{
	bool moveback;
	if (Distance > MinDistance)
	{
		moveback = false;
		if (Health >= OriginalHealth)
			Distance = Distance - Speed;
		else
			Distance = Distance - (Speed / 2);
	}
	else
	{
		moveback = true;
		if (Health >= (OriginalHealth / 2))
			Distance = Distance + Speed;
		else if (Health < (OriginalHealth / 2))
			Distance = Distance + (Speed / 2);
		if (Distance == MaxDistance)
			moveback = false;

	}
}
