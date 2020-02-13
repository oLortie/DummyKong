/*
Auteur: Équipe p-02
Fichier: Game.cpp
Date : 9 février 2020
Description : Implémentation des méthodes de la classe Game
*/

#include "Game.h"

Game::Game()
{
	player.getUserInput();
}

Game::~Game()
{

}

bool Game::start()
{
	system("cls");
	player.readController();
	
	if (player.getPlayer().LThumbStickX == -1)
	{
		if (level.getMap(mario.getPosition().x - 1, mario.getPosition().y) != MAP) mario.backward();
	}
	if (player.getPlayer().LThumbStickX == 1)
	{
		if (level.getMap(mario.getPosition().x + 1, mario.getPosition().y) != MAP) mario.forward();
	}
	if (player.getPlayer().LThumbStickY == 1)
	{
		if (level.getMap(mario.getPosition().x, mario.getPosition().y - 1) != MAP) mario.climb();
	}
	if (player.getPlayer().LThumbStickY == -1)
	{
		if (level.getMap(mario.getPosition().x, mario.getPosition().y + 1) != MAP) mario.fall();
	}

	for (int i = 0; i < MAX_HEIGHT; i++)
	{
		for (int j = 0; j < MAX_WIDTH; j++)
		{
			if (i == mario.getPosition().y && j == mario.getPosition().x) cout << "x";
			else if (level.getMap(i, j) == AIR) cout << " ";
			else if (level.getMap(i, j) == MAP) cout << "#";
		}
		cout << endl;
	}
	return true;
}

bool Game::pause()
{
	isPaused = true;
	return true;
}

Character Game::getMario()
{
	return mario;
}

Character Game::getDummyKong()
{
	return dummyKong;
}

void Game::updateLevel()
{
	level.update();
}
