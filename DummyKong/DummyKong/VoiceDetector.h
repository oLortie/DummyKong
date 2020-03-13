#pragma once

#define A 1
#define I 2
#define O 3
#define EUH 4
#define PERCENTAGE 10

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct VoiceInput
{
	uint16_t filter1 = 0;
	uint16_t filter2 = 0;
	uint16_t filter3 = 0;
	uint16_t filter4 = 0;
};

class VoiceDetector 
{
public: 
	VoiceDetector();
    ~VoiceDetector();
    VoiceInput readInput(void);
	VoiceInput calculateAverage(std::vector<VoiceInput> vector); /*return type could change depending on adc bits*/
	void trainPlayer(uint8_t phoneme);
	uint8_t findPhoneme(void);
	VoiceInput getReference(uint8_t phoneme);
	std::vector<VoiceInput> getVoiceBuffer();

private:
	std::vector<VoiceInput> voiceBuffer;
	VoiceInput referenceA;
	VoiceInput referenceI;
	VoiceInput referenceO;
	VoiceInput referenceEUH;

	/*VOICE_INPUT_T ReferenceA;
	VOICE_INPUT_T ReferenceI;
	VOICE_INPUT_T ReferenceO;
	VOICE_INPUT_T ReferenceEUH;*/
};



//typedef enum Phoneme
//{
//	A,
//	I,
//	O,
//	EUH
//}PHONEME_T;
