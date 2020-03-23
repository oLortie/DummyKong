/*
Auteur: Équipe p-02
Fichier: DummyKong.cpp
Date : 9 février 2020
Description : Fichier principal du jeu Dummy Kong
*/

#include "Game.h"
#include "XController.h"
#include "timer.h"
#include <iostream>

using namespace std;

int main()
{
	Game mainGame;

	timer t1([&]() {
		
		mainGame.refresh();
	}, 100);

	t1.start();
	
	std::cin.get();

	return 0;
}