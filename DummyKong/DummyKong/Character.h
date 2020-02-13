/*
Auteur: Équipe p-02
Fichier: Character.h
Date : 9 février 2020
Description : Déclaration de la classe Character
*/

#pragma once
#include <string>

using namespace std;

struct Coordonnees
{
	int x;
	int y;
};

class Character
{
private:
	int lifePoints;
	unsigned char lifeCount;
	string name;
	Coordonnees position;

public:
	Character();
	Character(int positionX, int positionY);
	virtual ~Character();
	int getLifePoints();
	void setLifePoints(int newLifePoints);
	unsigned char getLifeCount();
	void setLifeCount(unsigned char newLifeCount);
	string getName();
	void setName(string newName);
	bool jump();
	Coordonnees getPosition();
	bool forward();
	bool backward();
	bool climb();
	bool hit();

};
