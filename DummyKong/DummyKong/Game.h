/*
Auteur: �quipe p-02
Fichier: Game.h
Date : 9 f�vrier 2020
Description : D�claration de la classe Game
*/

#pragma once
#include "Level.h"
#include "Character.h"

class Game
{
private:
	Level level;
	Character mario;
	Character dummyKong;
	bool isPaused;

public:
	Game();
	virtual ~Game();
	bool start();
	bool pause();
	Character getMario();
	Character getDummyKong();
	void updateLevel();
};