#include "VoiceDetector.h"

VoiceDetector::VoiceDetector()
{
	referenceA = { 0, 0, 0, 0 };
	referenceI = { 0, 0, 0, 0 };
	referenceO = { 0, 0, 0, 0 };
	referenceEUH = { 0, 0, 0, 0 };
}

VoiceDetector::~VoiceDetector()
{
}

/*
lire le input du port série et stocker les valeurs dans une structure VoiceInput
*/
VoiceInput VoiceDetector::readInput()
{
	return referenceA;
}

/*
calculate the average of the buffer
*/
VoiceInput VoiceDetector::calculateAverage(std::vector<VoiceInput> vector)
{
	VoiceInput temp = {0, 0, 0, 0};
	for (int i = 0; i < voiceBuffer.size(); i++)
	{
		temp.filter1 += vector[i].filter1;
		temp.filter2 += vector[i].filter2;
		temp.filter3 += vector[i].filter3;
		temp.filter4 += vector[i].filter4;
	}

	// checker si les int16 font chier la moyenne

	temp.filter1 /= vector.size();
	temp.filter2 /= vector.size();
	temp.filter3 /= vector.size();
	temp.filter4 /= vector.size();

	return temp;
}

void VoiceDetector::trainPlayer(uint8_t phoneme)
{
	std::vector<VoiceInput> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(readInput());
		// delay?
	}

	

	switch (phoneme)
	{
	case A:
		referenceA = calculateAverage(vec);
		break;
	case I:
		referenceI = calculateAverage(vec);
		break;
	case O:
		referenceO = calculateAverage(vec);
		break;
	case EUH:
		referenceEUH = calculateAverage(vec);
		break;
	default:
		break;
	}
}

uint8_t VoiceDetector::findPhoneme()
{
	VoiceInput input = calculateAverage(voiceBuffer);

	return A;
}

VoiceInput VoiceDetector::getReference(uint8_t phoneme)
{
	switch (phoneme)
	{
	case A: return referenceA;
		break;
	case I: return referenceI;
		break;
	case O: return referenceO;
		break;
	case EUH: return referenceEUH;
		break;
	default: return referenceA;
		break;
	}
}

std::vector<VoiceInput> VoiceDetector::getVoiceBuffer()
{
	return voiceBuffer;
}