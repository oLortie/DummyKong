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
		if (level.getMap(mario.getPosition().y, mario.getPosition().x - 1) != MAP) mario.backward();
	}
	if (player.getPlayer().LThumbStickX == 1)
	{
		if (level.getMap(mario.getPosition().y, mario.getPosition().x + 1) != MAP) mario.forward();
	}
	if (player.getPlayer().LThumbStickY == 1)
	{
		if (level.getMap(mario.getPosition().y, mario.getPosition().x) == ECHELLE) mario.climb();
	}
	if (player.getPlayer().LThumbStickY == -1)
	{
		if (level.getMap(mario.getPosition().y + 1, mario.getPosition().x) == ECHELLE) mario.fall();
	}
	if (mario.getJumpingState() == 0 && level.getMap(mario.getPosition().y+1, mario.getPosition().x) == AIR) mario.fall();

	if (player.getPlayer().BTN_A == 1)
	{
		if (mario.getJumpingState() == 0 && level.getMap(mario.getPosition().y + 1, mario.getPosition().x) == MAP) mario.jump();
	}
	if (mario.getJumpingState() != 0) mario.jump();
	for (int i = 0; i < MAX_HEIGHT; i++)
	{
		for (int j = 0; j < MAX_WIDTH; j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			if (i == mario.getPosition().y && j == mario.getPosition().x) cout << "M";
			else if (level.getMap(i, j) == AIR)
			{
				cout << " ";
			}
			else if (level.getMap(i, j) == MAP)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "#";
			}
			else if (level.getMap(i, j) == ECHELLE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "H";
			}
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
