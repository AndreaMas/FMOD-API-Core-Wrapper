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

	class FModWrapper
	{
		FMOD::System* m_system;
		std::vector<FMOD::Sound*> m_sounds;
		std::vector<FMOD::Channel*> m_channels;

	public:
		FModWrapper();
		void Init(); // initialize FMOD
		void Play(int i_channel);
		void Pause(int i_channel);
		void Stop(int i_channel);
		void LoadMusicStaticToChannel(std::string i_path, int i_channel);
		void LoadMusicStreamToChannel(std::string i_path, int i_channel);
		void SetChannelVolume(int i_volume, int i_channel);
		void SetChannelPan(int i_pan, int i_channel);
	};



} // end of fmodw namespace
