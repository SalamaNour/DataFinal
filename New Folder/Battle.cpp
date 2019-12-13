#include "Battle.h" 
#include <time.h>

Battle::Battle()
{	
	EnemyCount = 0;
	INACFighterCount=0;
	INACFreezerCount=0;
	INACHealerCount=0;
	fightercount=0;
	freezercount=0;
	healercount=0;
	KilledCount = 0;
	ActiveCount = 0;
	FrostedCount = 0;
	CurrentTimeStep = 0;
	killedFigters = 0;
	KilledFreezers = 0;
	KilledHealers = 0;
	FrostedFighters = 0;
	FrostedFreezers = 0;
	FrostedHealers = 0;
	pGUI = NULL;
}



Castle*  Battle::GetCastle()
{
	return &BCastle;
}


void Battle::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();
	string inputFile;
	pGUI->PrintMessage("Enter File name to load then .txt -> Eg: 'test.txt'	");
	inputFile = pGUI->GetString();
	LoadFile(inputFile);

	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		break;
	case MODE_STEP:
		break;
	case MODE_SLNT:
		break;
	case MODE_DEMO:
		
		while(!Q_Inactive.isEmpty())
		{
			
			//CurrentTimeStep++;
			ActivateEnemies();
			MoveAll();
			pGUI->ResetDrawingList();
			AddAllListsToDrawingList();
			StatusBarInfo();
			pGUI->waitForClick();
			
			Freezer* pFR;
			
		for (int i=0;i<2;i++)
		{
			if (!Q_freezers.isEmpty())
			{
			  Q_freezers.dequeue(pFR);
			  pFR->SetStatus(FRST);
			  Q_Freezer_Frosted.enqueue(pFR);
			  FrostedFreezers++;
			  freezercount--;
			}
		}

			Healer* pH;
			
			for (int i=0;i<2;i++)
			{
				if(!S_healers.isEmpty())
				{
			  S_healers.pop(pH);
			  pH->SetStatus(FRST);
			  S_Healer_Frosted.push(pH);
			  FrostedHealers++;
			  healercount--;
				}
			}

			if(!S_Healer_Frosted.isEmpty())
			{
				S_Healer_Frosted.pop(pH);
			    pH->SetStatus(ACTV);
			    S_healers.push(pH);
			    healercount++;
			    FrostedHealers--;
			}

			if(!Q_Freezer_Frosted.isEmpty())
			{
				Q_Freezer_Frosted.dequeue(pFR);
			    pFR->SetStatus(ACTV);
			    Q_freezers.enqueue(pFR);
			    freezercount++;
			    FrostedFreezers--;
			}


			if(!S_healers.isEmpty())
			{
				S_healers.pop(pH);
			    pH->SetStatus(KILD);
			    Q_Killed.enqueue(pH);
			    KilledHealers++;
			    healercount--;
			}

			if(!Q_Freezer_Frosted.isEmpty())
			{
				Q_Freezer_Frosted.dequeue(pFR);
			    pFR->SetStatus(KILD);
			    Q_Killed.enqueue(pFR);
			    KilledFreezers++;
			    FrostedFreezers--;
			}

			CurrentTimeStep++;

		}

		break;
	}

	delete pGUI;
	
}



//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
void Battle::AddAllListsToDrawingList()// ana
{	
	Enemy* const * EnemyList = Q_Inactive.toArray(EnemyCount);// demo, queue has 2 pointers,
	for(int i=0; i<EnemyCount; i++)
		pGUI->AddToDrawingList(EnemyList[i]);

	Freezer* const* FrActList = Q_freezers.toArray(freezercount);
	for (int i = 0; i < freezercount;i++)
		pGUI->AddToDrawingList(FrActList[i]);

	ArrayStack<Healer*> SpareH;
	Healer *H;
	while (!S_healers.isEmpty())// msh fdya
	{
	
		S_healers.pop(H);
		pGUI->AddToDrawingList(H);
		SpareH.push(H);

	}
	while (!SpareH.isEmpty())
	{
		SpareH.pop(H);
		S_healers.push(H);
	}

	Freezer* const* FrfrzList = Q_Freezer_Frosted.toArray(FrostedFreezers);
	for (int i = 0; i < FrostedFreezers;i++)
		pGUI->AddToDrawingList(FrfrzList[i]);

	while (!S_Healer_Frosted.isEmpty())
	{
	
		S_Healer_Frosted.pop(H);
		pGUI->AddToDrawingList(H);
		SpareH.push(H);

	}
	while (!SpareH.isEmpty())
	{
		SpareH.pop(H);
		S_Healer_Frosted.push(H);
	}

	Enemy* const* KilledList=Q_Killed.toArray(KilledCount);
	for(int i=0; i<KilledCount; i++)
		pGUI->AddToDrawingList(KilledList[i]);

}

//check the inactive list and activate all enemies that has arrived
void Battle::ActivateEnemies()
{
	Enemy *pE;
	Healer*h; Freezer*fr; Fighter*fg;

	while (Q_Inactive.peekFront(pE))	//as long as there are more inactive enemies
	{
		if (pE->GetArrvTime() > CurrentTimeStep)	//no more arrivals at current time
			return;

		pE->SetStatus(ACTV);	//make status active
		Q_Inactive.dequeue(pE);	//remove enemy from the queue
		
		//Q_Active.enqueue(pE);



		//AddtoDemoList(pE);		//move it to demo list (for demo purposes)
		//dynamic cast
		h = dynamic_cast<Healer*>(pE);
		fr = dynamic_cast<Freezer*>(pE);
		fg = dynamic_cast<Fighter*>(pE);
		if (h != NULL)
		{
			S_healers.push(h);
			healercount++;
		}
		if (fr != NULL)
		{
			Q_freezers.enqueue(fr);
			freezercount++;
		}
		ActiveCount++;
		EnemyCount--;

	}
}

void Battle::MoveAll()
{
	Queue<Freezer*> Qsparefr;
	Freezer* pE;
	while (!Q_freezers.isEmpty())
	{
		Q_freezers.dequeue(pE);
		Qsparefr.enqueue(pE);
		pE->Move();
	}
	while (!Qsparefr.isEmpty())
	{
		Qsparefr.dequeue(pE);
		Q_freezers.enqueue(pE);
	}

	ArrayStack<Healer*> tempstackHeal;
	Healer* healptr;
	while (S_healers.pop(healptr))
	{
		tempstackHeal.push(healptr);
		healptr->Move();
	}
	while (tempstackHeal.pop(healptr))
	{
		S_healers.push(healptr);
	}
}



void Battle::LoadFile(const string File)
{
	
	 ifstream Input(File);
	 if(Input.is_open())
		 {
	    
		 int M;
		 int ID, TYP,AT;

		 BCastle.ReloadCastle(Input);
		 Input >> M; 
		 Enemy * PE;

		for (int i = 0; i < M; i++) 
		{
			Input >> ID;
			Input >> TYP;
			Input >> AT;

			if (TYP == 0)
			{
				PE = new Fighter(ID, AT); 
				PE->SetType(TYP);
			}
			else if (TYP == 2)
			{	
				PE = new Freezer(ID, AT);
				PE->SetType(TYP);
			}
			else if (TYP == 1)
			{
				PE = new Healer(ID, AT);
				PE->SetType(TYP);
			}
			PE->ReloadF(Input);
			EnemyCount++;
			PE->SetStatus(INAC);
		    Q_Inactive.enqueue(PE);

		}
		
	}

}

void Battle::AddEnemy(Enemy * arrE)
{
	if (EnemyCount < MaxEnemyCount)
		BEnemiesForDraw[EnemyCount++] = arrE;
		
}

//void Battle::AddFighter(Fighter * arrF)
//{
//	if (EnemyCount < MaxEnemyCount)
//		BEnemiesForDraw[INACFighterCount++] = arrF;
//
//}
//
//void Battle::AddFreezer(Freezer * arrFr)
//{
//	if (EnemyCount < MaxEnemyCount)
//		BEnemiesForDraw[INACFreezerCount++] = arrFr;
//
//}

//void Battle::AddHealer(Healer * arrH)
//{
//	if (EnemyCount < MaxEnemyCount)
//		BEnemiesForDraw[INACHealerCount++] = arrH;
//
//}



void Battle::CountEnemies(Enemy * E)
{
	for (int i = 0; i < EnemyCount; i++)
	{
		if (E->GetStatus() == ACTV)
		{
			ActiveCount++;
		}
		else if (E->GetStatus() == FRST)
		{
			FrostedCount++;
		}
		else if (E->GetStatus() == KILD)
		{
			KilledCount++;
		}
	}
	 
}

int Battle::GetACTFightersCount()
{
	return fightercount;
}

int Battle::GetACTFreezersCount()
{
	return freezercount;
}

int Battle::GetACTHealersCount()
{
	return healercount;
}

void Battle::StatusBarInfo()
{
	int a=BCastle.GetHealth();
	CASTLE_STATUS s=BCastle.getstatus();
	ActiveCount=fightercount+freezercount+healercount;
	FrostedCount=FrostedFighters+FrostedFreezers+FrostedHealers;
	KilledCount=killedFigters+KilledFreezers+KilledHealers;
	pGUI->UpdateInterface(CurrentTimeStep,a,s,fightercount,freezercount,healercount,ActiveCount,FrostedFighters,FrostedFreezers,FrostedHealers,FrostedCount,killedFigters,KilledFreezers,KilledHealers,KilledCount);
	
}