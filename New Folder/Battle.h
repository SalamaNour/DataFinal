#pragma once

#include "Enemies\Enemy.h"
#include "Fighter.h"
#include "Freezer.h"
#include "Healer.h"
#include "Castle\Castle.h"
#include "Generic_DS\Queue.h"
#include "Generic_DS/PrrQueue.h"
#include "Generic_DS/ArrayStack.h"
#include "GUI\GUI.h"
#include <fstream>
#include <iostream>
#include <string>
// it is the controller of the project
class Battle
{
private:
	GUI* pGUI;
	Castle BCastle;
	int EnemyCount;	//the actual number of enemies in the game
	int ActiveCount, FrostedCount, KilledCount;	//no. of enemies (Active, Frosted, killed so far)
	int INACFighterCount, INACHealerCount,INACFreezerCount;
	int CurrentTimeStep;
	int NoEnemies;
	int killedFigters;
	int KilledFreezers;
	int KilledHealers;
	int fightercount , freezercount, healercount;  
	//active fighter c
	//active freezer c
	//active healer c
	int FrostedFighters;
	int FrostedFreezers;
	int FrostedHealers;
	Enemy * BEnemiesForDraw[MaxEnemyCount]; // This Array of Pointers is used for drawing elements in the GUI
								  			// No matter what list type you are using to hold enemies, 
											// you must pass the enemies to the GUI function as an array of enemy pointers. 
											// At every time step, you should update those pointers 
											// to point to the current active enemies 
											// then pass the pointers list to the GUI function

	Queue<Enemy*> Q_Inactive;		//Queue of inactive enemies
	Queue<Enemy*> Q_Active;		//Queue of active enemies
	Queue<Enemy*> Q_Frosted;		//Queue of frosted enemies
	Queue<Enemy*> Q_Killed;		//Queue of killed enemies
	Queue<Fighter*>Q_fighter;
	Queue<Freezer*>Q_Freezer_Frosted;
	ArrayStack<Healer*>S_Healer_Frosted;
	ArrayStack<Healer*> S_healers; //active healers
	Queue<Freezer*> Q_freezers;   //active freezers




	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	//Queue for all enemies in the battle

	/// ==>


	//
	// TODO: Add More Data Members As Needed
	//

public:
	
	Battle();
	void AddAllListsToDrawingList();		//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
	Castle* GetCastle();
	void RunSimulation();
	void ActivateEnemies();		//check the inactive list and activate all enemies that has arrived
	void MoveAll();
	void LoadFile(const string File);
	void AddEnemy(Enemy *arrE);
	//void AddFighter(Fighter *arrF);
	//void AddFreezer(Freezer *arrFr);
	//void AddHealer(Healer *arrH);
	void DeleteEnemy(Enemy *arrEk);
	void CountEnemies(Enemy *E);
	int GetACTFightersCount();
	int GetACTFreezersCount();
	int GetACTHealersCount();
	void StatusBarInfo(); 
	//
	// TODO: Add More Member Functions As Needed
	//
};

