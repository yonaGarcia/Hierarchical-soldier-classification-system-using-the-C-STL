#pragma once
#include "Soldier.h"
class PrivateSoldier : public Soldier
{
protected:
	float * opGrade;
public:
	PrivateSoldier( int id, string privateName, string familyName ,int operationNum );
	PrivateSoldier(const PrivateSoldier& p);
	PrivateSoldier(PrivateSoldier&& p);
	~PrivateSoldier();
	
	void print();
	bool medal();
	string soldierType();

};
