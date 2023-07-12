#pragma once
#include"PrivateSoldier.h"
class Commander :public PrivateSoldier
{

	bool combatSoldier;
public:
	
	Commander(int id, string privateName, string familyName, int operationNum);
	Commander(const Commander & com);
	~Commander() ;
	string soldierType() override;
	bool medal() override;
	void print() override;
	bool getIs() ;
	


};