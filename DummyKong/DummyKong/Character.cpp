/*
Auteur: Équipe p-02
Fichier: Character.cpp
Date : 9 février 2020
Description : Implémentation des méthodes de la classe Character
*/

#include "Character.h"


Character::Character(int positionX, int positionY)
{
	position.x = positionX;
	position.y = positionY;
	jumping = false;
	falling = false;
	jumpingState = 0;
}

Character::~Character()
{

}


int Character::getLifePoints()
{
	return lifePoints;
}

void Character::setLifePoints(int newLifePoints)
{
	lifePoints = newLifePoints;
}

unsigned char Character::getLifeCount()
{
	return lifeCount;
}

void Character::setLifeCount(unsigned char newLifeCount)
{
	lifeCount = newLifeCount;
}

string Character::getName()
{
	return name;
}

void Character::setName(string newName)
{
	name = newName;
}

bool Character::jump()
{
	jumpingState++;
	position.y--;
	if (jumpingState == 3)
	{
		jumpingState = 0;
	}
	//else jump();

	return true;
}

Coordonnees Character::getPosition()
{
	return position;
}

bool Character::forward()
{
	position.x++;
	return true;
}

bool Character::backward()
{
	position.x--;
	return true;
}

bool Character::climb()
{
	position.y--;
	return true;
}

bool Character::fall()
{
	position.y++;
	return true;
}

bool Character::hit()
{
	return true;
}

bool Character::isJumping()
{
	return jumping;
}

bool Character::isFalling()
{
	return falling;
}

void Character::goUp()
{
	position.y--;
}

void Character::goDown()
{
	position.y++;
}

int Character::getJumpingState()
{
	return jumpingState;
}

