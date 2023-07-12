#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include"Soldier.h"
#include"PrivateSoldier.h"
#include"Commander.h"
#include"Officer.h"
using namespace std;

enum option {
	EXIT,	
	ADD_NEW_SOLDIER,	
	DESERVES_MEDAL,	
	HIGHEST_SOCIOMETRIC,	
	PRIVATE_MEDAL_COUNT,	
	NONCOMBAT_COMMANDER,	
	SUPER_SOLDIER,   
	REMOVE_OFFICER,
};


vector <Soldier*>::iterator itv;

void add(vector <Soldier*>& v)
{
	Soldier* sol;
	int choice; int id; string privateName; string familyName; int numOfOperation;
	cout << "choose a soldier\n";
	cout << "enter 1 to add a private\n";
	cout << "enter 2 to add a commander\n";
	cout << "enter 3 to add an officer\n";
	cin >> choice;
	cout << "enter id, first name, last name and number of operations\n";
	cin >> id >> privateName >> familyName >> numOfOperation;
	if (numOfOperation > 0 && (choice == 1 || choice == 2))
	{
		cout << "enter " << numOfOperation << " grades\n";
	}
	switch (choice)
	{
	case 1:
		sol = new PrivateSoldier(id, privateName, familyName, numOfOperation);
		v.push_back(sol);
		break;
	case 2:
		
		
		sol = new Commander(id, privateName, familyName, numOfOperation);
		v.push_back(sol);
		break;
	case 3:
		float soc;
		cout << "enter the sociometric score\n";
		cin >> soc;
		sol = new Officer(id, privateName, familyName, numOfOperation, soc);
		v.push_back(sol);
		break;
	default:
		break;
	}
}
void printMedalList(vector <Soldier*> v)
{
	for_each(v.begin(), v.end(), [](Soldier* a) {if (a->medal()) { a->print(); }});
}
Soldier* highesttSociometricScore(vector <Soldier*> v)
{
	vector<Soldier*>::iterator a = v.begin();
	while (((Soldier*)*a)->soldierType() != "officer")
	{
		a++;
	}
	vector<Soldier*>::iterator b = a + 1;
	for (; b != v.end(); b++)
	{
		if (((Soldier*)*b)->soldierType() == "officer")
		{
			if (((Officer*)*a)->getSoc() < ((Officer*)*b)->getSoc())
			{
				a = b;
			}
		}
	}
	return ((Soldier*)*a);
}

int main()
{

	Soldier* s;
	vector <Soldier*> v;
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER:add(v);  	
			break;
		case DESERVES_MEDAL:printMedalList(v);  
			break;
		case HIGHEST_SOCIOMETRIC:    
			s = highesttSociometricScore(v); 
			cout << "Officer with the highest sociometric score: ";
			cout << s->getFirstN() << ' ' << s->getFamilyN() << endl;
			break;
		case PRIVATE_MEDAL_COUNT:  cout << "number of privates that received medals: ";
			cout << count_if(v.begin(), v.end(), [](Soldier* a) {return (a->medal() && a->soldierType() == "private"); }) << endl;
			break;
		case NONCOMBAT_COMMANDER: cout << "list of noncombat commanders: "<<endl;    
			for_each(v.begin(), v.end(), [](Soldier* a) {if (a->soldierType() == "commander" && !((Commander*)a)->getIs()) cout << a->getFirstN() << " " << a->getFamilyN() << endl; });
			break;
		case SUPER_SOLDIER:
			if (any_of(v.begin(), v.end(), [](Soldier* a) {return (a->getNOF() > 15); })) 
			{
				cout << "there is at least one soldier that did more than 15 operations\n";
			}
			else
				cout << "no soldier did more than 15 operations\n";
			break;
		case REMOVE_OFFICER:
			
			auto a = remove_if(v.begin(), v.end(), [](Soldier* s) {return(s->soldierType() == "officer" && s->getNOF() <= 0); });
			for_each(v.begin(), a, [](Soldier* s) {s->print(); });
			break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}
