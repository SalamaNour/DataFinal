#include "Fighter.h"

#include <fstream>
#include <iostream>
#include <string>



Fighter::Fighter( int id,int arrTime, int type ,double H,double P,int Reloadtime,double speed):Enemy(id,arrTime)
{
	SetType(type);
	SetHealth(H);
	SetPower(P);
	SetReloadTime(Reloadtime);
	SetSpeed(speed);
	OriginalHealth = H;


}

Fighter::Fighter(int id, int arrTime):Enemy(id,arrTime)
{
}


Fighter::~Fighter()
{
}

void Fighter::Move()
{

	if (Distance > MinDistance && Health >= (OriginalHealth / 2))
		Distance = Distance - Speed;
	else if (Distance > MinDistance && Health < (OriginalHealth / 2))
		Distance = Distance - (Speed / 2);
	else
		Distance = MinDistance;

}
