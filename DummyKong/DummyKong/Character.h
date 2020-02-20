/*
Auteur: Équipe p-02
Fichier: Character.h
Date : 9 février 2020
Description : Déclaration de la classe Character
*/

#pragma once
#include <string>
#include "Level.h"
#define G 3
#include "timer.h"

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
	bool jumping;
	bool falling;
	int jumpingState;

public:
	Character(int positionX = 1, int positionY = MAX_HEIGHT - 2);
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
	bool fall();
	bool isFalling();
	bool isJumping();
	void goUp();
	void goDown();
	int getJumpingState();

};
