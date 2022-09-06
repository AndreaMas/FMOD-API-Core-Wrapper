#pragma once

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
	const int MAX_PAN = 10;
	const int MIN_PAN = -10;

	class FModWrapper
	{
		FMOD::System* mSystem;
		FMOD::Sound* mSounds[NUM_SOUNDS];
		FMOD::Channel* mChannels[NUM_CHANNELS];

	public:
		FModWrapper();
		~FModWrapper();
		void Init(); // initialize FMOD
		void PlaySongOnChannel(int sound, int channel);
		void PauseChannel(int channel);
		void StopChannel(int channel);
		void LoadStaticSound(std::string path, int sound);
		void LoadStreamingSound(std::string path, int sound);
		void LoadCompressedSound(std::string path, int sound);
		void SetLoop(int channel);
		void SetChannelVolume(int volume, int channel);
		void SetChannelPan(int channel, int pan);


	};

	// Utility
	int UserInputWithBounds(int low, int high);
	void LoadSomeSongs(fmodw::FModWrapper* const fmod);
	// Basic UI
	int MainMenuUI();
	void PlaySoundUI(fmodw::FModWrapper* const fmod);
	void PauseSoundUI(fmodw::FModWrapper* const fmod);
	void ChangeVolumeUI(fmodw::FModWrapper* const fmod);
	void PanUI(fmodw::FModWrapper* const fmod);
	void SetLoopUI(fmodw::FModWrapper* const fmod);

} // end of fmodw namespace
