/*
Auteur: �quipe p-02
Fichier: Tool.cpp
Date : 9 f�vrier 2020
Description : Impl�mentation des m�thodes de la classe Tool
*/

#include "Tool.h"

Tool::Tool()
{

}

Tool::~Tool()
{

}

Coordonnees Tool::getPosition()
{
	return position;
}

void Tool::setPosition(int x, int y) {
	position.x = x;
	position.y = y;
}

bool Tool::updatePosition()
{
	return true;
}
