#include "Commander.h"
#include "PrivateSoldier.h"
#include <iostream>



#include <string>
using namespace std;

Commander::Commander(int id, string privateName, string familyName, int operationNum) :PrivateSoldier(id, privateName,familyName, operationNum)
{
	int combat;
	cout << "enter 1 if the soldier is combat and 0 if not\n";
	cin >> combat;
	if (combat == 1)
	{
		this->combatSoldier = true;
	}
	else if (combat == 0)
	{
		this->combatSoldier = false;
	}
}
Commander::Commander(const Commander &com): PrivateSoldier(*this)
{
	combatSoldier = com.combatSoldier;
}
Commander::~Commander()
{
	if (opGrade)
	{
		delete opGrade;
		opGrade = nullptr;
	}
}
bool Commander::getIs()
{
	return combatSoldier;
}

void Commander::print()
{
	/*cout << soldierType ()<< endl;*/
	PrivateSoldier::print();
	cout << "combat: ";
	if (combatSoldier)
		cout << "yes" << endl;
	else cout << "no" << endl;
}

bool Commander::medal()
{
	float av = 0;
	for (int i = 0; i < myNumOfOperation; i++)
	{
		av += opGrade[i];
	}
	av /= myNumOfOperation;
	if (myNumOfOperation >= 7 && av > 90 && combatSoldier)
		return true;
	return false;
}

string Commander::soldierType()
{
	return "commander";
}
