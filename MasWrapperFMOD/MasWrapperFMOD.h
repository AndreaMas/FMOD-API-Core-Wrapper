#pragma once

#include <vector>

// FMOD fd
namespace FMOD {
	class System;
	class Sound;
	class Channel;
}

namespace fmodw {

	const int NUM_CHANNELS = 5;
	const int NUM_SOUNDS = 5;
	const int MAX_VOLUME = 10;

	class FModWrapper
	{
		FMOD::System* m_system;
		FMOD::Sound* m_sounds[NUM_SOUNDS];
		FMOD::Channel* m_channels[NUM_CHANNELS];

	public:
		FModWrapper();
		void Init(); // initialize FMOD
		void PlaySongOnChannel(int i_sound, int i_channel);
		void PauseChannel(int i_channel);
		void StopChannel(int i_channel);
		void LoadStaticSound(std::string i_path, int i_sound);
		void LoadStreamingSound(std::string i_path, int i_sound);
		void LoadCompressedSound(std::string i_path, int i_sound);
		void SetChannelVolume(int i_volume, int i_channel);
		void SetChannelPan(int i_pan, int i_channel);
	};



} // end of fmodw namespace
