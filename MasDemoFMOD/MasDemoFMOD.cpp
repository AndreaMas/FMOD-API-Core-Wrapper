#include <string>
#include <cstdlib>

#include "../MasWrapperFMOD/MasWrapperFMOD.h"


int main()
{
	// Initialize FMOD System
	fmodw::FModWrapper* fmod = new fmodw::FModWrapper();
	fmod->Init();

	LoadSomeSongs(fmod);

	while (1) {
		// Show main menu ui and take user input
		int choice = fmodw::MainMenuUI();
		// show different ui depending on choice taken
		if (choice == 1) fmodw::PlaySoundUI(fmod);
		if (choice == 2) fmodw::PauseSoundUI(fmod);
		if (choice == 3) fmodw::ChangeVolumeUI(fmod);
		if (choice == 4) fmodw::PanUI(fmod);
		if (choice == 5) fmodw::SetLoopUI(fmod);

	};
}
