/*
Auteur: �quipe p-02
Fichier: Character.h
Date : 9 f�vrier 2020
Description : D�claration de la classe Character
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
	int lifeCount;
	string name;
	Coordonnees position;
	int m_position_x;
	int m_position_y;
	bool jumping;
	bool falling;
	int jumpingState;

public:
	Character(int positionX = 1, int positionY = MAX_HEIGHT - 2);
	virtual ~Character();
	int const getLifePoints();
	void setLifePoints(int newLifePoints);
	unsigned char const getLifeCount();
	void setLifeCount(unsigned char newLifeCount);
	string const getName();
	void setName(string newName);
	bool jump();
	Coordonnees const getPosition();
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
	void takeDamage(int dmg);
	void gainLifePoints(int lifePts);

};
