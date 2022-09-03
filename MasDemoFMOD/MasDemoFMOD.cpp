#include <iostream>
#include <string>
#include "../MasWrapperFMOD/MasWrapperFMOD.h"

void PlaySoundUI(fmodw::FModWrapper*& fmod) {
	int sound, channel;
	std::cout << "Play what sound?" << std::endl;
	std::cout << "Sounds:" << std::endl;
	std::cout << "1) rain ambiance (1hour/streaming)" << std::endl;
	std::cout << "2) medium guitar track (3min/static)" << std::endl;
	std::cout << "3) short dog bark (1sec/compressed)" << std::endl;
	std::cin >> sound;
	std::cout << "Play on what channel? (1-10)" << std::endl;
	std::cin >> channel;
	fmod->PlaySongOnChannel(sound, channel);
}

void PauseSoundUI(fmodw::FModWrapper*& fmod) {
	int sound, channel;
	std::cout << "Stop what channel?" << std::endl;
	std::cout << "Play on what channel? (1-10)" << std::endl;
	std::cin >> channel;
	fmod->PauseChannel(channel);
}

void ChangeVolumeUI(fmodw::FModWrapper*& fmod) {
	int volume, channel;
	std::cout << "What channel are you changing volume to?" << std::endl;
	std::cin >> channel;
	std::cout << "Desired volume? (1-10)" << std::endl;
	std::cin >> volume;
	
	fmod->SetChannelVolume(volume, channel);
}


int main()
{
	// Initialize FMOD System
	fmodw::FModWrapper* fmod = new fmodw::FModWrapper();
	fmod->Init();

	// Load Ambiance Music as sound 1 (Streaming)
	std::string path1 = "./music/1hourRain.mp3";
	int channel1 = 1;
	int sound1 = 1;
	fmod->LoadStreamingSound(path1, sound1);
	
	// Load Guitar Music as sound 2 (Static)
	std::string path2 = "./music/2MinGuitarChorus.mp3";
	int channel2 = 2;
	int sound2 = 2;
	fmod->LoadStaticSound(path2, sound2);

	// Load short sound as sound 3 (Compressed)
	std::string path3 = "./music/1secDogBark.wav"; // test with compressed format ...
	int channel3 = 3;
	int sound3 = 3;
	fmod->LoadCompressedSound(path3, sound3);

	// Songs:
	// 1) rain ambiance (1hour/streaming)
	// 2) medium guitar track (3min/static)
	// 3) short dog bark (1sec/compressed)

	while (1) {
		int choice;
		std::cout << "What to do?" << std::endl;
		std::cout << "1) play song" << std::endl;
		std::cout << "2) stop song" << std::endl;
		std::cout << "3) change volume" << std::endl;
		std::cin >> choice;
		if (choice == 1) PlaySoundUI(fmod);
		if (choice == 2) PauseSoundUI(fmod);
		if (choice == 3) ChangeVolumeUI(fmod);

	};
}
