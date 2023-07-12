#pragma once
#include<string>
using namespace std;
class Soldier
{
protected:
	long int myID;
	string myFirstName;
	string myFamilyName;
	int myNumOfOperation;
public:
	Soldier();
	Soldier(int id, string privateName, string familyName, int numOfOperation);
	Soldier(const Soldier& s);
	virtual ~Soldier() ;
	virtual bool medal() = 0;
	virtual string soldierType() = 0;
	virtual void print();
	virtual long int getID();
	virtual string getFirstN();
	virtual string getFamilyN();
	virtual int getNOF();
	

};