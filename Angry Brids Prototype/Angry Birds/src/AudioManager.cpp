#include "AudioManager.h"
#include "irrKlang.h"
#include <assert.h>
#include <cstdlib>
#include <string>

AudioManager* AudioManager::ptrInstance = nullptr;

AudioManager::AudioManager()
{
	// initialize the sound system
	pSoundEng = irrklang::createIrrKlangDevice();

	const char* Music = "../../../../../reference/asset/angrybirds/audio/title_theme.mp3";

	// Play music: looped = true, paused = true, track = true
	pSong = pSoundEng->play2D(Music, true, true, true);
	pSong->setVolume(.2f);

}

void AudioManager::ToggleMusic()
{
	if (Instance().pSong->getIsPaused())
	{
		Instance().pSong->setPlayPosition(0);
		Instance().pSong->setIsPaused(false);
	}
	else
	{
		Instance().pSong->setIsPaused(true);
	}
}
void AudioManager::MusicOn()
{
	if (Instance().pSong->getIsPaused())
	{
		Instance().pSong->setPlayPosition(0);
		Instance().pSong->setIsPaused(false);
	}
}
void AudioManager::MusicOff()
{
	if (!Instance().pSong->getIsPaused())
	{
		Instance().pSong->setIsPaused(true);
	}
}

void AudioManager::BirdSquawk()
{
	irrklang::ISound *pSnd = nullptr;
	int n = rand() % 5;

	switch (n)
	{
	case 0:
		pSnd = Instance().pSoundEng->play2D("../../../../../reference/asset/angrybirds/audio/bird 02 collision a1.mp3", false, false, true);
		pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
		break;
	case 1:
		pSnd = Instance().pSoundEng->play2D("../../../../../reference/asset/angrybirds/audio/bird 02 collision a2.mp3", false, false, true);
		pSnd->drop();
		break;
	case 2:
		pSnd = Instance().pSoundEng->play2D("../../../../../reference/asset/angrybirds/audio/bird 02 collision a3.mp3", false, false, true);
		pSnd->drop();
		break;
	case 3:
		pSnd = Instance().pSoundEng->play2D("../../../../../reference/asset/angrybirds/audio/bird 02 collision a4.mp3", false, false, true);
		pSnd->drop();
		break;
	case 4:
	default:
		pSnd = Instance().pSoundEng->play2D("../../../../../reference/asset/angrybirds/audio/bird 02 collision a5.mp3", false, false, true);
		pSnd->drop();
		break;
	}
}

void AudioManager::Snort()
{
	irrklang::ISound *pSnd = nullptr;
	pSnd = Instance().pSoundEng->play2D("../../../../../reference/asset/angrybirds/audio/pig_bd.wav", false, false, true);
	pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
};
void AudioManager::Glass()
{
	irrklang::ISound *pSnd = nullptr;
	pSnd = Instance().pSoundEng->play2D("../../../../../reference/asset/angrybirds/audio/ice light collision a3.wav", false, false, true);
	pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
};
void AudioManager::Stone()
{
	irrklang::ISound *pSnd = nullptr;
	pSnd = Instance().pSoundEng->play2D("../../../../../reference/asset/angrybirds/audio/rock collision a2.wav", false, false, true);
	pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
};
void AudioManager::Wood()
{
	irrklang::ISound *pSnd = nullptr;
	pSnd = Instance().pSoundEng->play2D("../../../../../reference/asset/angrybirds/audio/wood collision a3.wav", false, false, true);
	pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
};
void AudioManager::Win()
{
	irrklang::ISound *pSnd = nullptr;
	pSnd = Instance().pSoundEng->play2D("../../../../../reference/asset/angrybirds/audio/level clear military a1.mp3", false, false, true);
	pSnd->drop(); // these are managed pointers: drop means you are not adding to the ref counting
};

void AudioManager::Terminate()
{
	delete ptrInstance;
}

AudioManager::~AudioManager()
{
	pSoundEng->stopAllSounds();
	pSoundEng->removeAllSoundSources();
	pSoundEng->drop();
}