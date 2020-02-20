/*
Auteur: Équipe p-02
Fichier: Level.cpp
Date : 9 février 2020
Description : Implémentation des méthodes de la classe Level
*/

#include "Level.h"

Level::Level(int level)
{
	index = level;

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

}

unsigned char Level::getDifficulty()
{
	return difficulty;
}

void Level::setDifficulty(unsigned char newDifficulty)
{
	difficulty = newDifficulty;
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
