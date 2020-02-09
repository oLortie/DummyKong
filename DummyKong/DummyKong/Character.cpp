/*
Auteur: �quipe p-02
Fichier: Character.cpp
Date : 9 f�vrier 2020
Description : Impl�mentation des m�thodes de la classe Character
*/

#include "Character.h"

Character::Character()
{

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

Movement Character::getMovement()
{
	return movement;
}
