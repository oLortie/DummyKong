/*
Auteur: �quipe p-02
Fichier: Level.h
Date : 9 f�vrier 2020
Description : D�claration de la classe Level
*/

#pragma once

#include <iostream>
#include "Hammer.h"

using namespace std;

#define MAX_WIDTH 30
#define MAX_HEIGHT 30
#define AIR 0
#define MAP 1
#define ECHELLE 2
#define PEACH 3
#define HAMMER 4

class Level
{
private:
	unsigned char difficulty;
	int map[MAX_HEIGHT][MAX_WIDTH] = { 0 };
	int index;
	bool complete;
	Hammer *hammer;

public:
	Level(int level = 1);
	virtual ~Level();

	unsigned char getDifficulty();
	int getMap(int i, int j);
	Hammer getHammer();
	Hammer* getHammerPtr();
	void setDifficulty(unsigned char newDifficulty);

	void update();
	bool isComplete();
	void completeLevel();
	bool checkAroundPlayer(int x, int y, int check);
};
