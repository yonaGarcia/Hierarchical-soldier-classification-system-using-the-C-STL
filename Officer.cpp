#include"Officer.h"
#include <iostream>
using namespace std;

Officer::Officer(int id, string privateName, string familyName, int operationNum, int grade) :Soldier(id, privateName, familyName, operationNum)
{
	this->socioGrade = grade;
}

Officer::Officer(const Officer& o) : Soldier(*this)
{
	socioGrade = o.socioGrade;
}

Officer::~Officer()
{

}

void Officer::print()
{
	cout << soldierType () << endl;
	Soldier::print();
	cout << "sociometric score:" << socioGrade << endl;
}

int Officer::getSoc()
{
	return socioGrade;
}

bool Officer::medal()
{
	if (myNumOfOperation > 2 && socioGrade >= 92)
		return true;
	return false;
}

string Officer::soldierType()
{
	return "officer";
}
