#pragma once
#include "Enemies/Enemy.h"
class Freezer :public Enemy
{
public:
	Freezer(int id, int arrTime, int type ,double H,double P,int Reloadtime,double speed);
	Freezer(int id, int arrTime);
	~Freezer();
	void Move();
};

