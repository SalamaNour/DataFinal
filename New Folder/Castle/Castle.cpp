#pragma once  
#include "Castle.h"

#include <fstream>
#include <iostream>
#include <string>



Castle::Castle()
{
	setstatus(ACTIVE);
}

void Castle::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
}

double Castle::GetHealth() const
{
	return Health;
}

void Castle::SetCastlePower(double CP)
{
	if (CP > 0)
	   Castle_power= CP;
	else
		Castle_power = 0;
}

double Castle::GetCastlepower()
{
	return Castle_power;
}

void Castle::SetN(int n)
{
	if (n > 0)
		maxEnem = n;
	else
		maxEnem = 1;

}

int Castle::GetN()
{
	return maxEnem;
}

void Castle::setstatus(CASTLE_STATUS stat)
{
	status = stat;
}

CASTLE_STATUS Castle::getstatus()
{
	return status;
}

void Castle::ReloadCastle(ifstream & Input)
{
	
		Input >> Health;
		Input >> maxEnem;
		Input >> Castle_power;
		this->SetHealth(Health);
		SetN(maxEnem);
		SetCastlePower(Castle_power);
}

Castle::~Castle()
{
}

