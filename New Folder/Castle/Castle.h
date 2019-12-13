#pragma once
#include "..\Defs.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;



class Castle
{
	double Health;
	double Castle_power;
	int maxEnem;
	CASTLE_STATUS status;
	//
	// TODO: Add More Data Members As Needed
	//

public:
	Castle();
	void SetHealth(double h);
	double GetHealth()const;
	void SetCastlePower(double CP);
	double GetCastlepower();
	void SetN(int n);
	int GetN();
	void setstatus(CASTLE_STATUS stat);
	CASTLE_STATUS getstatus();
	void ReloadCastle(ifstream& Input);
	~Castle();
	//
	// TODO: Add More Member Functions As Needed
	//

};

