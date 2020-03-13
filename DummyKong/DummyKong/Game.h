/*
Auteur: �quipe p-02
Fichier: Game.h
Date : 9 f�vrier 2020
Description : D�claration de la classe Game
*/

#pragma once
#include "Level.h"
#include "Character.h"
#include "XController.h"

using namespace std;

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
	bool refresh();
	bool pause();
	Character const getMario();
	Character const getDummyKong();
	void updateLevel();
	void showLevel();

};
