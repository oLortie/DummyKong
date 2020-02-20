/*
Auteur: Équipe p-02
Fichier: Level.h
Date : 9 février 2020
Description : Déclaration de la classe Level
*/

#pragma once

#include <iostream>

using namespace std;

#define MAX_WIDTH 30
#define MAX_HEIGHT 30
#define AIR 0
#define MAP 1
#define ECHELLE 2

class Level
{
private:
	unsigned char difficulty;
	int map[MAX_HEIGHT][MAX_WIDTH] = { 0 };
	int index;

public:
	Level(int level = 1);
	virtual ~Level();
	unsigned char getDifficulty();
	void setDifficulty(unsigned char newDifficulty);
	void update();
	int getMap(int i, int j);
};
