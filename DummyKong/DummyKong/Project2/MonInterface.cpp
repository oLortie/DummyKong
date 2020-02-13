/*
*   Voir fichier d'entête pour informations.
*   
*   $Author: bruc2001 $
*   $Date: 2018-02-13 08:54:36 -0500 (mar., 13 févr. 2018) $
*   $Revision: 108 $
*   $Id: MonInterface.cpp 108 2018-02-13 13:54:36Z bruc2001 $
*
*   Copyright 2013 Département de génie électrique et génie informatique
*                  Université de Sherbrooke  
*/
#include <QStyleFactory>
#include "MonInterface.h"
#include <fstream>
#include <ostream>

MonInterface::MonInterface(const char * theName) : VisiTest(theName)
{
	donnee.typeTest = 1;
	donnee.registreSW = 1;
	donnee.retourSW = 1;

	donnee.registreLD = 1;
	donnee.valeurLD = 1;

	donnee.etatLD = 1;
	donnee.etatSW = 1;
	applicationActive = false;

	resetTest();
	resetArchive();
}



void MonInterface::sauvegarder(char *NomFichier)
{
	std::fstream myFile;
	myFile.open(NomFichier, std::ios::out);
	for (int i = 0; i < listTest.getSize(); i++)
	{
		myFile << listTest[i];
	}
	myFile.close();
	
}
void MonInterface::demarrer()
{
	applicationActive = true;
	message("l'archivage est démarré");
}
void MonInterface::arreter()
{
	applicationActive = false;
	message("l'archivage est arrêté");
}
void MonInterface::vider()
{
	listTest.clear();
	message("Vider les archives");
}
void MonInterface::modeFile()
{
	mode = LAFILE; /* mode file */ 
	message("Mode File");
}
void MonInterface::modePile()
{
	mode = LAPILE;  /* mode pile */
	message("Mode File");
}
void MonInterface::suivant()
{
	if (mode == LAFILE)
	{

		if (listTest.getSize() != 0)
		{
			if (listTest.getPosition() == listTest.getSize())
			{
				message("Il n'y a pas de test suivant!");
			}
			else
			{
				++listTest;
				setArchive(listTest[listTest.getPosition()]);
				setArchive((listTest.getPosition() + 1), listTest.getCapacity());
			}
		}
	}
		else 
		{
		if (listTest.getSize() != 0)
		{
			if (listTest.getPosition() == listTest.getSize())
			{
				message("Il n'y a pas de test suivant!");
			}
			else
			{
				//listTest-=listTest[listTest.getPosition() -1];
				setArchive(listTest[listTest.getPosition()]);
				setArchive((listTest.getPosition() + 1), listTest.getCapacity());
			}
		}
		}
}
void MonInterface::precedent()
{
	if (mode == LAPILE)
	{
		if (listTest.getSize() != 0)
		{
			setArchive(listTest[0]);
			setArchive(listTest.getPosition() + 1, listTest.getCapacity());
		}
	}
	else
	{
		if (listTest.getSize() != 0)
		{
			--listTest;
			setArchive(listTest[listTest.getPosition()]);
			setArchive((listTest.getPosition() + 1), listTest.getCapacity());
		}
	}

}
void MonInterface::premier()
{
	if (listTest.getSize() > 0)
	{
		setArchive(listTest[0]);
		setArchive(listTest.getPosition() + 1, listTest.getCapacity());
	}
}
void MonInterface::dernier()
{
	if (listTest.getSize() > 0)
	{
		setArchive(listTest[listTest.getSize()]);
		setArchive(listTest.getPosition() + 1, listTest.getCapacity());
	}
}
bool MonInterface::getapplicationActive()
{
	return this->applicationActive;
}
void MonInterface::testSuivant()
{
	resetTest();

	donnee.typeTest++;
	if (donnee.typeTest == 4) donnee.typeTest = 1;
	/* Test toyota echo*/
	if (donnee.typeTest == 1)
	{
		
		int val;

		if (fpga.lireRegistre(SW, val) == true)
		{
			fpga.ecrireRegistre(10, val);
			donnee.valeurLD = val;
		}
	}
	/* Test parite*/
	if (donnee.typeTest == 2)
	{
		bool lecture;
		int val, a;
		int count = 0;
		lecture = fpga.lireRegistre(SW, val);

		for (int i = 0; i < 8; i++)
		{
			a = (exp2(i));
			if (val & a)
			{
				count++;
			}
		}
#ifdef DEBUG_
		std::cout << count << std::endl;
#endif
		if (count % 2 == 0)
		{
			donnee.valeurLD = 0xFF;
			std::cout << "valeur : " << val << std::endl;
			fpga.ecrireRegistre(LD, 0xFF);
		}
		else
		{
			donnee.valeurLD = 0x00;
			fpga.ecrireRegistre(LD, 0x00);
		}
		
	}
	/* Test histogramme*/
	if (donnee.typeTest == 3)
	{
		bool lecture = false;
		int val = 0;
		int NLC = 0;
		int q = 0;

		lecture = fpga.lireRegistre(SW, val);
		std::cout << "valeur : " << val << std::endl;

		NLC = (log(val + 1) / log(2));

		std::cout << "Nombre de leds consecutives : " << NLC << std::endl;

		if (NLC == 0)
		{
			//std::cout << "NLC" << std::endl;
			fpga.ecrireRegistre(LD, NLC);
		}
		else
		{
			for (int i = 0; i < NLC; i++)
			{
				//std::cout << "allo" << i << std::endl;
				q += (exp2(i));
			}

			fpga.ecrireRegistre(LD, q);
		}
		std::cout << "valeur de q : " << q << std::endl;
		std::cout << "fin" << std::endl;

		donnee.valeurLD = q;
	}

	donnee.registreSW = 8;
	donnee.registreLD = 10;

	donnee.etatLD = donnee.valeurLD;

	fpga.lireRegistre(donnee.registreSW, donnee.retourSW);
	donnee.etatSW = donnee.retourSW;

	setTest(donnee);

	if (getapplicationActive()) std::cout << "archive est active" <<std::endl;

	if (getapplicationActive())
	{
		listTest += donnee;
		setArchive(listTest[0]);
		setArchive(listTest.getPosition() + 1, listTest.getSize());
	}
}

/*******************
Test #1: Affiche letat des switch sur les leds
*******************/
bool MonInterface::testEcho()
{
	int val;
	
	if (fpga.lireRegistre(SW, val) == true)
	{
		fpga.ecrireRegistre(10, val);
		return true;
	}
	else
		return false;
}
/*******************
Test #2:
*******************/
bool MonInterface::testParite()
{
	bool lecture;
	int val, a;
	int count = 0;
	lecture =  fpga.lireRegistre(SW, val);

	for (int i = 0; i < 8; i++)
	{
		a = (exp2(i));
		if (val & a)
		{
			count++;
		}
	}
#ifdef DEBUG_
	std::cout << count << std::endl;
#endif
	if (count % 2 == 0)
	{
		std::cout << "valeur : " << val << std::endl;
		fpga.ecrireRegistre(LD, 0xFF);
	}
	else
	{
		fpga.ecrireRegistre(LD, 0x00);
	}
	return true;
}


/*******************
Test#3
*******************/
bool MonInterface::HistogrammeLed()
{
	bool lecture = false;
	int val = 0;
	int NLC = 0;
	int q = 0;

	lecture = fpga.lireRegistre(SW, val);
	std::cout << "valeur : " << val << std::endl;

	NLC = (log(val + 1) / log(2));

	std::cout << "Nombre de leds consecutives : " << NLC << std::endl;

	if (NLC == 0)
	{
		std::cout << "NLC" << std::endl;
		fpga.ecrireRegistre(LD, NLC);
	}
	else
	{
		for (int i = 0; i < NLC; i++)
		{
			std::cout << "allo" << i << std::endl;
			q += (exp2(i));
		}

		fpga.ecrireRegistre(LD, q);
	}
	std::cout << "valeur de q : " << q << std::endl;
	std::cout << "fin" << std::endl;

	return true;
}

std::ostream& operator<<(std::ostream& os,DonneesTest &data)
{
	os << "Les donnees du test sont: " << std::endl;
	os << "Type test: " << data.typeTest << std::endl;
	os << "Adresse switches: "<< data.registreSW << std::endl;
	os << "Retour switches: " << data.retourSW << std::endl;
	os << "Etat switches: " << data.etatSW << std::endl;
	os << "Adresse leds: " << data.registreLD << std::endl;
	os << "Valeur leds: " << data.valeurLD << std::endl;
	os << "Etat leds: " << data.etatLD << std::endl;
	return os;
}
