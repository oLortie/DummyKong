/*
Auteur: �quipe p-02
Fichier: Barrel.h
Date : 13 f�vrier 2020
Description : D�claration de la classe Barrel
*/

#pragma once
#include "Tool.h"
#include "Character.h"

class Barrel:public Tool
{	
public:
	Barrel(Coordonnees positionInitiale);
	~Barrel();
	bool bounce();
	void roll(bool direction);
	//bool fall();
};
