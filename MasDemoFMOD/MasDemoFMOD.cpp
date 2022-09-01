#include <iostream>
#include <string>
#include "../MasWrapperFMOD/MasWrapperFMOD.h"

using namespace fmodw;

int main()
{
	// Initialize FMOD System
	FModWrapper* f = new FModWrapper();

	// Load Static Music to Channel
	std::string path1 = "./music/somesong.mp3";
	int channel1 = 1;
	f->LoadMusicStaticToChannel(path1, channel1);
}
