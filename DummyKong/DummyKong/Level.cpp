/*
Auteur: Équipe p-02
Fichier: Level.cpp
Date : 9 février 2020
Description : Implémentation des méthodes de la classe Level
*/

#include "Level.h"

Level::Level(int level)
{
	hammer = new Hammer(10, MAX_HEIGHT - 2);
	index = level;
	complete = false;

	switch (index)
	{
	case 1:
		for (int i = 0; i < MAX_HEIGHT; i++)
		{
			for (int j = 0; j < MAX_WIDTH; j++)
			{
				if (i == MAX_HEIGHT - 10) map[i][j] = MAP;
				if (i == 0 || i == MAX_HEIGHT - 1 || j == 0 || j == MAX_WIDTH - 1) map[i][j] = MAP;
			}
		}
		for (int k = MAX_HEIGHT - 2; k >= MAX_HEIGHT - 10; k--)
		{
			map[k][MAX_WIDTH - 10] = ECHELLE;
		}
		map[hammer->getPosition().y][hammer->getPosition().x] = HAMMER;
		map[MAX_HEIGHT - 11][1] = PEACH;
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}

Level::~Level()
{
	delete hammer;
}

unsigned char Level::getDifficulty()
{
	return difficulty;
}

void Level::setDifficulty(unsigned char newDifficulty)
{
	difficulty = newDifficulty;
}

Hammer Level::getHammer() {
	return *hammer;
}

Hammer* Level::getHammerPtr() {
	return hammer;
}

void Level::update()
{
	system("cls");

	for (int i = 0; i < MAX_HEIGHT; i++)
	{
		for (int j = 0; j < MAX_WIDTH; j++)
		{
			switch (map[i][j])
			{
			case AIR:
				cout << " ";
				break;
			case MAP:
				cout << "#";
				break;
			case ECHELLE:
				cout << "1";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}

int Level::getMap(int i, int j)
{
	return map[i][j];
}

bool Level::isComplete()
{
	return complete;
}

void Level::completeLevel()
{
	complete = true;
}

bool Level::checkAroundPlayer(int x, int y, int check)
{
	if (map[y + 1][x] == check) return true;
	if (map[y - 1][x] == check) return true;
	if (map[y][x + 1] == check) return true;
	if (map[y][x - 1] == check) return true;
	return false;
}
