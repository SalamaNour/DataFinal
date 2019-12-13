#pragma once
#include "Enemies/Enemy.h"
class Healer :public Enemy
{
public:
	Healer(int id, int arrTime, int type ,double H,double P,int Reloadtime,double speed);
	Healer(int id, int arrTime);
	~Healer();
	void Move();
};

