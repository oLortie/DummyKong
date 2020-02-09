/*
Auteur: Équipe p-02
Fichier: Tool.h
Date : 9 février 2020
Description : Déclaration de la classe Tool
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
