#include"Soldier.h"
#include <string>
#include<iostream>
using namespace std;

Soldier::Soldier() : myID(0), myNumOfOperation(0)
{
}

Soldier::Soldier(int id, string privateName, string familyName, int numOfOperation)
{
	myID = id;
	myNumOfOperation = numOfOperation;
	myFamilyName = familyName;
	myFirstName = privateName;

}

Soldier::Soldier(const Soldier& s)//cctor
{
	myID = s.myID;
	myFamilyName = s.myFamilyName;
	myFirstName = s.myFirstName;
	myNumOfOperation = s.myNumOfOperation;

}

Soldier::~Soldier()
{
}

void Soldier::print()
{
	cout << "ID: ";
	cout << myID << endl;
	cout << "first name: ";
	cout << myFirstName << endl;
	cout << "last name: ";
	cout << myFamilyName << endl;
	cout << "num operations: ";
	cout << myNumOfOperation << endl;
}

long int Soldier::getID()
{
	return myID;
}

string Soldier::getFirstN()
{
	return myFirstName;
}

string Soldier::getFamilyN()
{
	return myFamilyName;
}

int Soldier::getNOF()
{
	return myNumOfOperation;
}

string Soldier::soldierType()
{
	return string();
}
