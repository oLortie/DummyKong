/*
Auteur: Équipe p-02
Fichier: Game.h
Date : 9 février 2020
Description : Déclaration de la classe Game
*/

#pragma once
#include "Level.h"
#include "Character.h"
#include "XController.h"

class Game
{
private:
	Level level;
	Character mario;
	Character dummyKong;
	bool isPaused;
	XController player;

public:
	Game();
	virtual ~Game();
	bool start();
	bool pause();
	Character const getMario();
	Character const getDummyKong();
	void updateLevel();
};
