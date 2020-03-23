/*
Auteur: �quipe p-02
Fichier: Movement.cpp
Date : 9 f�vrier 2020
Description : Impl�mentation des m�thodes de la classe Movement
*/

#include "Movement.h"

Movement::Movement()
{

}

Movement::~Movement()
{

}

bool Movement::jump()
{
	return true;
}

bool Movement::forward()
{
	position.x++;
	return true;
}

bool Movement::backward()
{
	position.x--;
	return true;
}

bool Movement::climb()
{
	position.y++;
	return true;
}

bool Movement::hit()
{
	return true;
}

Coordonnees Movement::getPosition()
{
	return position;
}
