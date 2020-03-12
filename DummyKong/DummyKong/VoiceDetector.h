#pragma once

#include <algorithm>
#include <vector>
#include <iostream>


class VoiceDetector 
{
public: 
	VoiceDetector();
    ~VoiceDetector();
    VOICE_INPUT_T readInput(void);
	uint8_t calculateAverage(void); /* return type could change depending on adc bits */
	void trainPlayer(PHONEME_T phoneme);
	PHONEME_T findPhoneme(void);
	VOICE_INPUT_T getReference(PHONEME_T phoneme);
	std::vector<VOICE_INPUT_T> getVoiceBuffer();

	

private:

	std::vector<VOICE_INPUT_T> voiceBuffer;
	VOICE_INPUT_T ReferenceA;
	VOICE_INPUT_T ReferenceI;
	VOICE_INPUT_T ReferenceO;
	VOICE_INPUT_T ReferenceEUH;

};

typedef struct VoiceInput
{
	uint16_t filter1 = 0;
	uint16_t filter2 = 0;
	uint16_t filter3 = 0;
	uint16_t filter4 = 0;
}VOICE_INPUT_T;

typedef enum
{
	A,
	I,
	O,
	EUH
}PHONEME_T;
