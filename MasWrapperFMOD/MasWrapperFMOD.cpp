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
	m_channels.clear();
}

void fmodw::FModWrapper::Init()
{
	std::cout << "FModWrapper Initialization ..." << std::endl;

	// Create the main system object
	FMOD_RESULT result = FMOD::System_Create(&m_system);
	if (result != FMOD_OK)
	{
		std::cout << "FMOD creation of main system object failed: " << std::endl;
		std::cout << FMOD_ErrorString(result) << std::endl;
		return;
	}

	// FMOD initialization
	result = m_system->init(NUM_CHANNELS, FMOD_INIT_NORMAL, 0);
	if (result != FMOD_OK)
	{
		std::cout << "FMOD initialization failed: " << std::endl;
		std::cout << FMOD_ErrorString(result) << std::endl;
		return;
	}
}


void fmodw::FModWrapper::Play(int i_channel)
{

}

void fmodw::FModWrapper::Pause(int i_channel)
{

}

void fmodw::FModWrapper::Stop(int i_channel)
{

}

void fmodw::FModWrapper::LoadMusicStaticToChannel(std::string i_path, int i_channel)
{
	//FMOD_RESULT System::createSound(
	//	const char* name_or_data,
	//	FMOD_MODE mode,
	//	FMOD_CREATESOUNDEXINFO * exinfo,
	//	Sound * *sound
	//);
}

void fmodw::FModWrapper::LoadMusicStreamToChannel(std::string i_path, int i_channel)
{

}

void fmodw::FModWrapper::SetChannelVolume(int i_volume, int i_channel)
{

}

void fmodw::FModWrapper::SetChannelPan(int i_pan, int i_channel)
{

}

