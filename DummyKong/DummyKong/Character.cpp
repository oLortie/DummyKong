/*
Auteur: Équipe p-02
Fichier: Character.cpp
Date : 9 février 2020
Description : Implémentation des méthodes de la classe Character
*/

#include "Character.h"

Character::Character()
{

}
Character::Character(int positionX, int positionY)
{
	position.x = positionX;
	position.y = positionY;
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
	position.y--;
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
	return true;
}

bool hit()
{
	return true;
}

