/*
Auteur: Équipe p-02
Fichier: Character.h
Date : 9 février 2020
Description : Déclaration de la classe Character
*/

#pragma once
#include <string>
#include "Level.h"
#include "timer.h"
#include "Hammer.h"

#define G 3

using namespace std;

class Character
{
private:
	int lifePoints;
	int lifeCount;
	string name;
	Coordonnees position;
	bool jumping;
	bool falling;
	int jumpingState;
	Hammer *hammer;

public:
	Character(int positionX = 1, int positionY = MAX_HEIGHT - 2);
	virtual ~Character();

	int getLifePoints();
	int getLifeCount();
	string getName();
	Coordonnees getPosition();

	void setName(string newName);
	void setLifeCount(int newLifeCount);
	void setLifePoints(int newLifePoints);

	
	bool forward();
	bool backward();
	bool climb();
	bool hit();
	void goUp();
	void goDown();

	bool jump();
	bool fall();
	bool isFalling();
	bool isJumping();
	int getJumpingState();

	void takeDamage(int dmg);
	void gainLifePoints(int lifePts);
	void attachHammer(Hammer *gameHammer);

};
