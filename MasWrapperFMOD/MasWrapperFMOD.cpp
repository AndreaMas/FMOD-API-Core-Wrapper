#include "pch.h"
#include "framework.h"

#include <fmod.hpp>
#include <fmod_errors.h>

#include <iostream>
#include <string>

#include "MasWrapperFMOD.h"



fmodw::FModWrapper::FModWrapper() :
	mSystem(nullptr),
	mChannels(),
	mSounds()
{
}

fmodw::FModWrapper::~FModWrapper()
{
	for (int i = 0; i < NUM_CHANNELS; ++i) {
		if (mChannels[i] != nullptr)
			mChannels[i]->stop();
	}
	for (int i = 0; i < NUM_SOUNDS; ++i) {
		if (mSounds[i] != nullptr)
			mSounds[i]->release();
	}
	mSystem->release();
}

void fmodw::FModWrapper::Init()
{
	std::cout << "FMOD Wrapper awakens ..." << std::endl;

	// Create the main system object
	FMOD_RESULT result = FMOD::System_Create(&mSystem);

	if (result != FMOD_OK)
	{
		std::cout << "[FAILED] FMOD creation of main system: ";
		std::cout << FMOD_ErrorString(result) << std::endl;
		exit(EXIT_FAILURE);
	}

	// FMOD initialization
	result = mSystem->init(NUM_CHANNELS, FMOD_INIT_NORMAL, 0);

	if (result != FMOD_OK)
	{
		std::cout << "[FAILED] FMOD initialization: ";
		std::cout << FMOD_ErrorString(result) << std::endl;
		exit(EXIT_FAILURE);
	}
}

void fmodw::FModWrapper::LoadStaticSound(std::string path, int sound)
{
	FMOD_RESULT result = mSystem->createSound(
		path.c_str(),
		FMOD_CREATESAMPLE,
		nullptr,
		&mSounds[sound]
	);

	if (result != FMOD_OK) {
		std::cout << "[FAILED] Loading Static music: ";
		std::cout << FMOD_ErrorString(result) << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "SUCCESS Loading Static music." << std::endl;
}

void fmodw::FModWrapper::LoadStreamingSound(std::string path, int sound)
{
	FMOD_RESULT result = mSystem->createSound(
		path.c_str(),
		FMOD_CREATESTREAM,
		nullptr,
		&mSounds[sound]
	);

	if (result != FMOD_OK) {
		std::cout << "[FAILED] Loading Streaming music: ";
		std::cout << FMOD_ErrorString(result) << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "SUCCESS Loading Streaming music." << std::endl;

}

void fmodw::FModWrapper::LoadCompressedSound(std::string path, int sound)
{
	FMOD_RESULT result = mSystem->createSound(
		path.c_str(),
		FMOD_CREATECOMPRESSEDSAMPLE,
		nullptr,
		&mSounds[sound]
	);

	if (result != FMOD_OK) {
		std::cout << "[FAILED] Loading Compressed music: ";
		std::cout << FMOD_ErrorString(result) << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "SUCCESS Loading Static music." << std::endl;
}

void fmodw::FModWrapper::SetLoop(int channel)
{
	int numLoops = 10;
	FMOD_RESULT result = mChannels[channel]->setLoopCount(numLoops); // TODO: Does not work ...

	if (result != FMOD_OK) {
		std::cout << "[FAILED] Loop was not set: ";
		std::cout << FMOD_ErrorString(result) << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "SUCCESS Loading Static music." << std::endl;
}

void fmodw::FModWrapper::PlaySongOnChannel(int sound, int channel)
{
	FMOD_RESULT result = mSystem->playSound(
		mSounds[sound],
		nullptr,
		false,
		&mChannels[channel]
	);

	if (result != FMOD_OK) {
		std::cout << "[FAILED] playing song on channel: ";
		std::cout << FMOD_ErrorString(result) << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "SUCCESS playing song on channel." << std::endl;
}

void fmodw::FModWrapper::PauseChannel(int channel)
{
	FMOD_RESULT result = mChannels[channel]->setPaused(true);
	if (result != FMOD_OK)
	{
		std::cout << "[FAILED] playing song on channel: ";
		std::cout << FMOD_ErrorString(result) << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "SUCCESS pausing song on channel." << std::endl;
}

void fmodw::FModWrapper::StopChannel(int channel)
{
	FMOD_RESULT result = mChannels[channel]->stop();
	if (result != FMOD_OK)
	{
		std::cout << "[FAILED] stopping channel: ";
		std::cout << FMOD_ErrorString(result) << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "SUCCESS pausing song on channel." << std::endl;
}

void fmodw::FModWrapper::SetChannelVolume(int volume, int channel)
{
	float volumeF = (float)volume / 10.0f;
	FMOD_RESULT result = mChannels[channel]->setVolume(volumeF);
	if (result != FMOD_OK)
	{
		std::cout << "[FAILED] setting channel volume." << std::endl;
		std::cout << FMOD_ErrorString(result) << std::endl;
		return;
	}

}

void fmodw::FModWrapper::SetChannelPan(int channel, int pan)
{
	float panF = (float)pan / 10.0f;
	FMOD_RESULT result = mChannels[channel]->setPan(panF);
	if (result != FMOD_OK)
	{
		std::cout << "[FAILED] setting channel pan." << std::endl;
		std::cout << FMOD_ErrorString(result) << std::endl;
		return;
	}

}

/*
* ******************************************************************
* *** UI & UTILITY *************************************************
* ******************************************************************
*/

int fmodw::UserInputWithBounds(int low, int high)
{
	int userInput;
	bool outOfBounds = true;
	while (outOfBounds) {
		std::cin >> userInput;
		if (userInput < low || userInput > high) {
			printf("Value outside range [%d, %d]. Retry:\n", low, high);
		}
		else {
			outOfBounds = false;
		}
	}
	return userInput;
}

void fmodw::LoadSomeSongs(fmodw::FModWrapper* const fmod) {
	// Load Ambiance Music as sound 1 (Streaming)
	std::string path1 = "./music/1hourRain.mp3";
	int sound1 = 1;
	fmod->LoadStreamingSound(path1, sound1);

	// Load Guitar Music as sound 2 (Static)
	std::string path2 = "./music/2MinGuitarChorus.mp3";
	int sound2 = 2;
	fmod->LoadStaticSound(path2, sound2);

	// Load short Bark as sound 3 (Compressed)
	std::string path3 = "./music/1secDogBark.wav"; // test with compressed format ...
	int sound3 = 3;
	fmod->LoadCompressedSound(path3, sound3);

	// Load short Sneeze as sound 4 (Compressed)
	std::string path4 = "./music/1secSneeze.wav"; // test with compressed format ...
	int sound4 = 4;
	fmod->LoadCompressedSound(path4, sound4);

	// Load Thunder as sound 5 (Static)
	std::string path5 = "./music/thunder20sec.wav";
	int sound5 = 5;
	fmod->LoadStaticSound(path5, sound5);
}

int fmodw::MainMenuUI() {
	std::system("cls");
	const int NUM_CHOICES = 5;
	// Display channel volume
	std::cout << std::endl << "Available actions:" << std::endl;
	std::cout << "1) PLAY sound" << std::endl;
	std::cout << "2) STOP sound" << std::endl;
	std::cout << "3) VOLUME change" << std::endl;
	std::cout << "4) PAN change" << std::endl;
	std::cout << "5) LOOP channel" << std::endl;
	return UserInputWithBounds(1, NUM_CHOICES);
}

void fmodw::PlaySoundUI(fmodw::FModWrapper* const fmod) {
	int sound, channel;
	std::cout << "Available Sounds:" << std::endl;
	std::cout << "1) rain ambiance (1hour/streaming)" << std::endl;
	std::cout << "2) medium guitar track (3min/static)" << std::endl;
	std::cout << "3) short dog bark (1sec/compressed)" << std::endl;
	std::cout << "4) short sneeze (1sec/compressed)" << std::endl;
	std::cout << "5) thunder (20sec/static)" << std::endl;
	sound = UserInputWithBounds(1, fmodw::NUM_SOUNDS);
	printf("Play on what channel? [%d, %d]\n", 1, fmodw::MAX_VOLUME);
	channel = UserInputWithBounds(1, fmodw::NUM_CHANNELS);
	fmod->PlaySongOnChannel(sound, channel);
}

void fmodw::PauseSoundUI(fmodw::FModWrapper* const fmod) {
	int channel;
	printf("Stop what channel? [%d, %d]\n", 1, fmodw::MAX_VOLUME);
	channel = UserInputWithBounds(1, fmodw::NUM_CHANNELS);
	fmod->PauseChannel(channel);
}

void fmodw::ChangeVolumeUI(fmodw::FModWrapper* const fmod) {
	int volume, channel;
	printf("Change volume on what CHANNEL? [%d, %d]\n", 1, fmodw::MAX_VOLUME);
	channel = UserInputWithBounds(1, fmodw::NUM_CHANNELS);
	printf("Desired VOLUME? [%d, %d]\n", 1, fmodw::MAX_VOLUME);
	volume = UserInputWithBounds(1, fmodw::MAX_VOLUME);
	fmod->SetChannelVolume(volume, channel);
}

void fmodw::PanUI(fmodw::FModWrapper* const fmod) {
	int volume, channel;
	printf("Change pan on what CHANNEL? [%d, %d]\n", 1, fmodw::MAX_VOLUME);
	channel = UserInputWithBounds(1, fmodw::NUM_CHANNELS);
	printf("Desired PAN? [%d, %d]\n", fmodw::MIN_PAN, fmodw::MAX_PAN);
	volume = UserInputWithBounds(1, fmodw::MAX_PAN);
	fmod->SetChannelPan(volume, channel);
}

void fmodw::SetLoopUI(fmodw::FModWrapper* const fmod) {
	int volume, channel;
	printf("Set Loop on what CHANNEL? [%d, %d]\n", 1, fmodw::MAX_VOLUME);
	channel = UserInputWithBounds(1, fmodw::NUM_CHANNELS);
	fmod->SetLoop(channel);
}

