/*
Auteur: �quipe p-02
Fichier: Tool.h
Date : 9 f�vrier 2020
Description : D�claration de la classe Tool
*/

#pragma once
#include "Movement.h"

class Tool
{
private:
	Coordonnees position;
public:
	Tool();
	virtual ~Tool();
	Coordonnees getPosition();
	bool updatePosition();
};
