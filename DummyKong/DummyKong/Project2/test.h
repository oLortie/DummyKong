#include"CommunicationFPGA.h"
#include<iostream>
#include<ostream>
#include<cstdint>
#include<cmath>

#define _DEBUG__

Registre registre;

/*******************
Test #1: Affiche letat des switch sur les leds
*******************/
bool testEcho()
{
	int val;
	
	if (fpga.lireRegistre (SW, val) == true)
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
bool testParite()
{
	unsigned char mask[8] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40,0x80 };
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
bool HistogrammeLed()
{
	bool lecture = false;
	int val = 0;
	int NLC = 0;
	int q = 0;

	lecture = fpga.lireRegistre(SW, val);
	std::cout << "valeur : " << val << std::endl;

	NLC = (log(val + 1) / log(2));

	std::cout << "Nombre de led consecutive : " << NLC << std::endl;

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