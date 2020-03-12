#include "VoiceDetector.h"

PHONEME_T phoneme;

VoiceDetector::VoiceDetector()
{

}
VOICE_INPUT_T VoiceDetector::readInput()
{

	return ReferenceA;
}
uint8_t VoiceDetector::calculateAverage()
{

}
void VoiceDetector::trainPlayer(PHONEME_T phoneme)
{
	
}
PHONEME_T VoiceDetector::findPhoneme()
{
	PHONEME_T tempPhoneme;

	return tempPhoneme;
}
VOICE_INPUT_T VoiceDetector::getReference(PHONEME_T phoneme)
{
	switch (phoneme)
	{
	case A: return ReferenceA;
		break;
	case I: return ReferenceI;
		break;
	case O: return ReferenceO;
		break;
	case EUH: return ReferenceEUH;

		break;
	default: return ReferenceA;
		break;
	}
}
std::vector<VOICE_INPUT_T> VoiceDetector::getVoiceBuffer()
{

}