#pragma once
#include "Enemies/Enemy.h"
class Fighter :public Enemy
{
public:
	Fighter(int id, int arrTime, int type ,double H,double P,int Reloadtime,double speed );
	Fighter(int id, int arrTime);
	~Fighter();
	void Move();

};

