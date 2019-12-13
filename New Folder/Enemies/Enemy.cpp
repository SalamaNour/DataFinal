#include "Enemy.h"


Enemy::Enemy(int id, int arrTime, int d):ID(id),ArrvTime(arrTime)
{
	SetDistance(d);
}

Enemy::Enemy( int id,int arrTime, int type ,double H,double P,int Reloadtime,double speed): ID(id), ArrvTime(arrTime)
{
	SetType(type);
	SetHealth(H);
	SetPower(P);
	SetReloadTime(Reloadtime);
	SetSpeed(speed);


}

Enemy::~Enemy()
{
}

int Enemy::GetID() const
{
	return ID;
}


void Enemy::SetStatus(ENMY_STATUS s)
{
	status = s;
}

void Enemy::SetType(int T)
{
	Type = T;
}

int Enemy::GetType()
{
	return Type;
}


ENMY_STATUS Enemy::GetStatus() const
{
	return status;
}


void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}



int Enemy::GetArrvTime() const
{
	return ArrvTime;
}

void Enemy::SetPower(double P)
{
	if (P > 0)
	{
		Power = P;
	}
	else
		Power = 0;
}

double Enemy::GetPower()
{
	return Power;
}

void Enemy::SetReloadTime(int RT)
{
	if (RT > 0)
	{
		ReloadTime = RT;
	}
	else
	{
		ReloadTime = 0;
	}
}

int Enemy::GetReloadTime()
{
	return ReloadTime;
}

void Enemy::SetHealth(int H)
{
	if (H > 0)
	{
		Health = H;
	}
	else
	{
		Health = 0;
	}
}

double Enemy::GetHealth()
{
	return Health;
}

void Enemy::SetOriginalHealth(int H)
{
	if (H > 0)
	{
		OriginalHealth = H;
	}
	else
	{
		OriginalHealth = 0;
	}
}

double Enemy::GetOriginalHealth()
{
	return OriginalHealth;
}

void Enemy::SetSpeed(int S)
{
	if (S > 0)
	{
		Speed = S;
	}
	else
	{
		Speed = 0;
	}
}

double Enemy::GetSpeed()
{
	return Speed;
}

void Enemy::ReloadF(ifstream & Input)
{
	Input >> Health;
	Input >> Power;
	Input >> ReloadTime;
	Input >> Speed;
	SetType(Type);
	SetOriginalHealth(Health);
	SetHealth(Health);
	SetPower(Power);
	SetReloadTime(ReloadTime);
	SetSpeed(Speed);
}