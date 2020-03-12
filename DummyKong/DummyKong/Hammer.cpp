/*
Auteur: Équipe p-02
Fichier: Hammer.cpp
Date : 11 mars 2020
Description : Implémentation des méthodes de la classe Hammer
*/

#include "Hammer.h"

Hammer::Hammer(int x, int y) {
	setPosition(x, y);
	attached = false;
}

Hammer::~Hammer() {

}

bool Hammer::isAttached() {
	return attached;
}

void Hammer::attach() {
	attached = true;
}

bool Hammer::breakBarrel() {
	return true;
}