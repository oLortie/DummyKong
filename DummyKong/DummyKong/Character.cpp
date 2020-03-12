/*
Auteur: �quipe p-02
Fichier: Character.cpp
Date : 9 f�vrier 2020
Description : Impl�mentation des m�thodes de la classe Character
*/

#include "Character.h"


Character::Character(int positionX, int positionY)
	:m_position_x(positionX), m_position_y(positionY)
{
	position.x = positionX;
	position.y = positionY;
	jumping = false;
	falling = false;
	jumpingState = 0;
	lifePoints = 100;
	lifeCount = 5;
}

Character::~Character()
{

}


int const Character::getLifePoints()
{
	return lifePoints;
}

void Character::setLifePoints(int newLifePoints)
{
	lifePoints = newLifePoints;
}

unsigned char const Character::getLifeCount()
{
	return lifeCount;
}

void Character::setLifeCount(int newLifeCount)
{
	lifeCount = newLifeCount;
}

string const Character::getName()
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

Coordonnees const Character::getPosition()
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

void Character::takeDamage(int dmg)
{
	lifePoints -= dmg;
	if (lifePoints < 0) lifePoints = 0;
	if (lifePoints == 0 && lifeCount > 0)
	{
		lifeCount--;
		lifePoints = 100;
	}
}

void Character::gainLifePoints(int lifePts)
{
	if (lifePoints + lifePts <= 100) lifePoints += lifePts;
}

