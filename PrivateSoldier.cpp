#include "PrivateSoldier.h"
#include <iostream>

using namespace std;


PrivateSoldier::PrivateSoldier(int id, string privateName, string familyName, int operationNum) :Soldier(id, privateName, familyName, operationNum)
{
    this->opGrade = new float [myNumOfOperation];
    for (int i = 0; i < this->myNumOfOperation; i++)
    {
        cin >> this->opGrade[i];
    }

}

PrivateSoldier::PrivateSoldier(const PrivateSoldier& p) :Soldier(*this)
{
    this->opGrade = new float [p.myNumOfOperation];
    for (int i = 0; i < myNumOfOperation; i++)
    {
        opGrade[i] = p.opGrade[i];
    }
}

PrivateSoldier::PrivateSoldier(PrivateSoldier&& p) :Soldier(p)
{
    this->opGrade = new float [p.myNumOfOperation];
    for (int i = 0; i < myNumOfOperation; i++)
    {
        opGrade[i] = p.opGrade[i];
    }
    p.opGrade = nullptr;
}
PrivateSoldier::~PrivateSoldier()
{
    if (opGrade)
    {
        delete opGrade;
        opGrade = nullptr;
    }
}

void PrivateSoldier::print()
{
    cout << soldierType ()<< endl;
    Soldier::print();
    if (this->myNumOfOperation != 0)
    {
        cout << "grades: ";
        for (int i = 0; i < myNumOfOperation; i++)
        {
            cout << opGrade[i] << " ";
        }
        cout << endl;
    }
}

bool PrivateSoldier::medal()
{
    float av = 0;
    for (int i = 0; i < myNumOfOperation; i++)
    {
        av += opGrade[i];
    }
    av /= myNumOfOperation;
    if (myNumOfOperation >= 10 && av > 95)
        return true;
    return false;
}

string PrivateSoldier::soldierType()
{
    return "private";
}
