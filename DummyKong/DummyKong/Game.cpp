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
	isPaused = false;
}

Game::~Game()
{

}

bool Game::refresh()
{
	system("cls");
	player.readController();

	if (mario.getLifeCount() == 0)
	{
		//game over
		cout << "==============================" << endl;
		cout << "GAME OVER!" << endl;
		cout << "==============================" << endl;
		cout << "Press START to exit" << endl;
		cout << "==============================" << endl;
		if (player.getPlayer().BTN_START == 1)
		{
			exit(EXIT_SUCCESS);
		}
	}
	else if (isPaused)
	{
		// menu pause
		cout << "==============================" << endl;
		cout << "PAUSE MENU" << endl;
		cout << "==============================" << endl;
		cout << "A - Reprendre" << endl;
		cout << "B - Quitter" << endl;
		cout << "==============================" << endl;

		if (player.getPlayer().BTN_A == 1)
		{
			start();
		}
		if (player.getPlayer().BTN_B == 1)
		{
			exit(EXIT_SUCCESS);
		}
		if (player.getPlayer().BTN_START == 1)
		{
			start();
		}
	}
	else if (level.isComplete())
	{
		cout << "==============================" << endl;
		cout << "YOU WON!" << endl;
		cout << "==============================" << endl;
		cout << "Press START to exit" << endl;
		cout << "==============================" << endl;
		if (player.getPlayer().BTN_START == 1)
		{
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		// jeu
		if (player.getPlayer().BTN_START == 1)
		{
			pause();
		}
		if (player.getPlayer().left_Trigger == 1)
		{
			mario.takeDamage(10);
		}
		if (player.getPlayer().right_Trigger == 1)
		{
			mario.gainLifePoints(10);
		}
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
		if (mario.getJumpingState() == 0 && level.getMap(mario.getPosition().y + 1, mario.getPosition().x) == AIR) mario.fall();

		if (player.getPlayer().BTN_A == 1)
		{
			if (mario.getJumpingState() == 0 && level.getMap(mario.getPosition().y + 1, mario.getPosition().x) == MAP) mario.jump();
		}
		if (mario.getJumpingState() != 0) mario.jump();
		
		if (level.checkAroundPlayer(mario.getPosition().x, mario.getPosition().y, PEACH)) level.completeLevel();

		showLevel();
		
	}

	return true;
}

bool Game::pause()
{
	isPaused = true;
	return true;
}

bool Game::start()
{
	isPaused = false;
	return true;
}

Character const Game::getMario()
{
	return mario;
}

Character const Game::getDummyKong()
{
	return dummyKong;
}

void Game::showLevel()
{
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
			else if (level.getMap(i, j) == PEACH)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				cout << "P";
			}
		}
		cout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "Life Points : " << mario.getLifePoints() << endl;
	cout << "Life count : " << mario.getLifeCount() << endl;
}
