/*
Auteur: �quipe p-02
Fichier: Game.cpp
Date : 9 f�vrier 2020
Description : Impl�mentation des m�thodes de la classe Game
*/

#include "Game.h"

//	DEFINITION OF GAME MODE: (XBOX CONTROLLER OR KEYBOARD)
/*
#define MOVE_LEFT player.getPlayer().LThumbStickX
#define MOVE_RIGHT player.getPlayer().LThumbStickX
#define MOVE_UP player.getPlayer().LThumbStickY
#define MOVE_DOWN player.getPlayer().LThumbStickY
#define JUMP player.getPlayer().BTN_A
*/
#define MOVE_LEFT KeyboardPress('A')
#define MOVE_RIGHT KeyboardPress('D')
#define MOVE_UP KeyboardPress('W')
#define MOVE_DOWN KeyboardPress('S')
#define JUMP KeyboardPress(' ')


int KeyboardPress(char ch) {
	if (GetAsyncKeyState(ch)) {
		if (ch == 'A' || ch == 'S') {
			return -1;
		}
		else {
			return 1;
		}
	}
	return 0;
}


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
		cout << "A/Enter - Reprendre" << endl;
		cout << "B/Esc - Quitter" << endl;
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
	// VOIR POUR DE LA SURCHARGE D'OPERATEURS
	else if (mario.getPosition().x == level.getHammer().getPosition().x && mario.getPosition().y == level.getHammer().getPosition().y && !level.getHammer().isAttached()) {
		mario.attachHammer(level.getHammerPtr());
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
		if (MOVE_LEFT == -1)
		{
			if (level.getMap(mario.getPosition().y, mario.getPosition().x - 1) != MAP) mario.backward();
		}
		if (MOVE_RIGHT == 1)
		{
			if (level.getMap(mario.getPosition().y, mario.getPosition().x + 1) != MAP) mario.forward();
		}
		if (MOVE_UP == 1)
		{
			if (level.getMap(mario.getPosition().y, mario.getPosition().x) == ECHELLE) mario.climb();
		}
		if (MOVE_DOWN == -1)
		{
			if (level.getMap(mario.getPosition().y + 1, mario.getPosition().x) == ECHELLE) mario.fall();
		}
		if (mario.getJumpingState() == 0 && level.getMap(mario.getPosition().y + 1, mario.getPosition().x) == AIR) mario.fall();

		if (JUMP == 1)
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

Character Game::getMario()
{
	return mario;
}

Character Game::getDummyKong()
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
			else if (level.getMap(i, j) == HAMMER && !level.getHammer().isAttached()) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << "T";
			}
			else {
				cout << " ";	// REMPLACE LE MARTEAU PAR DE L'AIR LORSQU'IL EST RAMASSE, POURRAIT ETRE CHANGER DANS LA MAP DIRECTEMENT
			}
		}
		cout << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "Life Points : " << mario.getLifePoints() << endl;
	cout << "Life count : " << mario.getLifeCount() << endl;
}
