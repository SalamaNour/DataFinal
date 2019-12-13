#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

#include <fstream>
#include <iostream>
#include <string>


class GUI;
// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Enemy
{

protected:
	const int ID;         //Each enemy has a unique ID (sequence number)
	const int ArrvTime;	//arrival time (time it starts to join battle)

	ENMY_STATUS status;	    //status of the enemy (inactive, inactive, frosted, killed)
	int Type;
	int Distance;	//Horizontal distance between enemy & the tower of its region
					//Always positive (ranges from 2 to 60)
	double Health;	//Enemy health
	double OriginalHealth;
	double Power;
	double Speed;
	int ReloadTime;
	int FirstShotTime;
	int EnemyKilledTime;
	int NextAttackTime;
	int K;  // for each enemy (Damage equation)
	int FD; //first shot delay
	int KD; //
	int LT; // LifeTime

	//
	// TODO: Add More Data Members As Needed
	//

public:
	Enemy(int id, int arrTime, int d = MaxDistance);
	Enemy(int id, int arrTime, int type ,double H,double P,int Reloadtime,double speed );
	virtual ~Enemy();

	int Enemy::GetID() const;
	ENMY_STATUS GetStatus() const;
	void SetStatus(ENMY_STATUS);

	void SetType(int T);
	int GetType();

	void DecrementDist();

	void SetDistance(int);
	int GetDistance() const;

	int GetArrvTime() const;

	void SetPower(double P);
	double GetPower();

	void SetReloadTime(int RT);
	int GetReloadTime();

	void SetHealth(int H);
	double GetHealth();

	void SetOriginalHealth(int H);
	double GetOriginalHealth();

	void SetSpeed(int S);
	double GetSpeed();
	void ReloadF(ifstream &Input);
	


	
	// Virtual Functions: ----------------

	virtual void Move() = 0;	//All enemies can move    
	//virtual void Act() = 0;	//Acting means fighting or healing

	//
	// TODO: Add More Member Functions As Needed
	//

};

