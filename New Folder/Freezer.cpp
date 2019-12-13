#include "Freezer.h"
#include "Enemies\Enemy.h"
#include <fstream>
#include <iostream>
#include <string>



Freezer::Freezer(int id, int arrTime, int type ,double H,double P,int Reloadtime,double speed):Enemy(id,arrTime)
{
	SetType(type);
	SetHealth(H);
	SetPower(P);
	SetReloadTime(Reloadtime);
	SetSpeed(speed);
	OriginalHealth = H;


}

Freezer::Freezer(int id, int arrTime):Enemy(id,arrTime)
{
}


Freezer::~Freezer()
{
}

void Freezer::Move()
{
	if (Distance > MinDistance && Health >= (OriginalHealth / 2))
		Distance = Distance - Speed;
	else if (Distance > MinDistance && Health < (OriginalHealth / 2))
		Distance = Distance - (Speed / 2);
	else
		Distance = MinDistance;

}
