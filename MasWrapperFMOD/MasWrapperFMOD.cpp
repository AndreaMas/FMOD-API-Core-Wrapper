#include "pch.h"
#include "framework.h"

#include <fmod.hpp>
#include <fmod_errors.h>

#include <iostream>
#include <string>
#include <vector>

#include "MasWrapperFMOD.h"



fmodw::FModWrapper::FModWrapper() :
	m_system(nullptr),
	m_channels(),
	m_sounds()
{
}

void fmodw::FModWrapper::Init()
{
	std::cout << "FMOD Wrapper awakens from the shadow realm ..." << std::endl;

	// Create the main system object
	FMOD_RESULT result = FMOD::System_Create(&m_system);

	if (result != FMOD_OK)
	{
		std::cout << "FAIL during FMOD creation of main system: " << std::endl;
		std::cout << FMOD_ErrorString(result) << std::endl;
		return;
	}

	// FMOD initialization
	result = m_system->init(NUM_CHANNELS, FMOD_INIT_NORMAL, 0);

	if (result != FMOD_OK)
	{
		std::cout << "FAIL during FMOD initialization: " << std::endl;
		std::cout << FMOD_ErrorString(result) << std::endl;
		return;
	}
}

void fmodw::FModWrapper::LoadStaticMusicToSounds(std::string i_path, int i_sound)
{
	//FMOD::Sound* sound;
	FMOD_RESULT result = m_system->createSound(
		i_path.c_str(),
		FMOD_CREATESAMPLE,
		nullptr,
		&m_sounds[i_sound]
	);
	//m_sounds[i_sound] = sound;

	if (result != FMOD_OK) {
		std::cout << "FAIL during Loading Static music:" << std::endl;
		std::cout << FMOD_ErrorString(result) << std::endl;
		return;
	}

	std::cout << "SUCCESS Loading Static music:" << std::endl;
}

void fmodw::FModWrapper::LoadStreamingMusicToSounds(std::string i_path, int i_sound)
{
	FMOD_RESULT result = m_system->createSound(
		i_path.c_str(),
		FMOD_CREATESTREAM,
		nullptr,
		&m_sounds[i_sound]
	);

	if (result != FMOD_OK) {
		std::cout << "FAIL during Loading Streaming music:" << std::endl;
		std::cout << FMOD_ErrorString(result) << std::endl;
		return;
	}

	std::cout << "SUCCESS Loading Streaming music:" << std::endl;

}

void fmodw::FModWrapper::PlaySongOnChannel(int i_sound, int i_channel)
{
	FMOD_RESULT result = m_system->playSound(
		m_sounds[i_sound],
		nullptr,
		false,
		&m_channels[i_channel]
	);

	if (result != FMOD_OK) {
		std::cout << "FAIL when playing song on channel:" << std::endl;
		std::cout << FMOD_ErrorString(result) << std::endl;
		return;
	}

	std::cout << "SUCCESS playing song on channel." << std::endl;
}

void fmodw::FModWrapper::Pause(int i_channel)
{

}

void fmodw::FModWrapper::Stop(int i_channel)
{

}

void fmodw::FModWrapper::SetChannelVolume(int i_volume, int i_channel)
{

}

void fmodw::FModWrapper::SetChannelPan(int i_pan, int i_channel)
{

}

