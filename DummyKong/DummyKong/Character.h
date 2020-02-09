/*
Auteur: �quipe p-02
Fichier: Character.h
Date : 9 f�vrier 2020
Description : D�claration de la classe Character
*/

#pragma once
#include "Movement.h"
#include <string>

using namespace std;

class Character
{
private:
	int lifePoints;
	unsigned char lifeCount;
	string name;
	Movement movement;

public:
	Character();
	virtual ~Character();
	int getLifePoints();
	void setLifePoints(int newLifePoints);
	unsigned char getLifeCount();
	void setLifeCount(unsigned char newLifeCount);
	string getName();
	void setName(string newName);
	Movement getMovement();

};
