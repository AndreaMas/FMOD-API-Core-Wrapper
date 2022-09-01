#include <iostream>
#include <string>
#include "../MasWrapperFMOD/MasWrapperFMOD.h"

using namespace fmodw;

int main()
{
	// Initialize FMOD System
	FModWrapper* fmod = new FModWrapper();
	fmod->Init();

	// Load Static Music to Channel
	std::string path1 = "./music/birds.wav";
	int channel1 = 1;
	int sound1 = 1;
	fmod->LoadStaticMusicToSounds(path1, sound1);
	fmod->PlaySongOnChannel(sound1, channel1);

	while (1);
}
