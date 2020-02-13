/*
Auteur: �quipe p-02
Fichier: Game.cpp
Date : 9 f�vrier 2020
Description : Impl�mentation des m�thodes de la classe Game
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
	/*isPaused = false;
	return true;*/
	system("cls");
	player.readController();
	for (int i = 0; i < MAX_HEIGHT; i++)
	{
		for (int j = 0; j < MAX_WIDTH; j++)
		{
			if (i == mario.getPosition().y && j == mario.getPosition().x) cout << "x";
			
		}
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
