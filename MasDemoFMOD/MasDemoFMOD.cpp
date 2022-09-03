#include <iostream>
#include <string>
#include "../MasWrapperFMOD/MasWrapperFMOD.h"


int main()
{
	// Initialize FMOD System
	fmodw::FModWrapper* fmod = new fmodw::FModWrapper();
	fmod->Init();

	// Load Static Music to Channel
	std::string path1 = "./music/birds.wav";
	int channel1 = 1;
	int sound1 = 1;
	fmod->LoadStaticMusicToSounds(path1, sound1);
	fmod->PlaySongOnChannel(sound1, channel1);

	while (1);
}
