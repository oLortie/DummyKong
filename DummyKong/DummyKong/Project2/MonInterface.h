/*
*   La classe MonInterface teste l'interface usager VisiTest (librairie).
*   
*   $Author: bruc2001 $
*   $Date: 2018-02-13 08:54:36 -0500 (mar., 13 févr. 2018) $
*   $Revision: 108 $
*   $Id: MonInterface.h 108 2018-02-13 13:54:36Z bruc2001 $
*
*   Copyright 2016 Département de génie électrique et génie informatique
*                  Université de Sherbrooke  
*/
#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include<cmath>
#include "VisiTest.h"
#include "myVector.h"
#include "CommunicationFPGA.h"

#define LAPILE 1
#define LAFILE 2

class MonInterface : public VisiTest
{
public:
	MonInterface(const char *theName);
	bool testEcho();
	bool testParite();
	bool HistogrammeLed();
	bool getapplicationActive();

	
public slots:
	virtual void sauvegarder(char* NomFichier);
	virtual	void testSuivant();
	virtual void demarrer();
	virtual void arreter();
	virtual void vider();
	virtual void modeFile();
	virtual void modePile();
	virtual void suivant();
	virtual void precedent();
	virtual void premier();
	virtual void dernier();
	
private:
	DonneesTest donnee;
	myVector<DonneesTest> listTest;
	CommunicationFPGA fpga;
	bool applicationActive;
	Registre registre;
	int mode;
};

std::ostream& operator<<(std::ostream& os, DonneesTest &data);

#endif // MONINTERFACE_H










