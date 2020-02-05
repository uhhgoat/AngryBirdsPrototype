#include "AudioManager.h"
#include "irrKlang.h"
#include <assert.h>
#include <cstdlib>

AudioManager* AudioManager::ptrInstance = nullptr;

AudioManager::AudioManager()
{
	// initialize the sound system
	pSoundEng = irrklang::createIrrKlangDevice();
}

void AudioManager::StartMusic()
{
	// Play music: looped = true, paused = false, track = true
	irrklang::ISound* pSong = Instance().pSoundEng->play2D("../../../../reference/asset/angrybirds/audio/title_theme.mp3", true, false, true);
	pSong->setVolume(.2f);
	assert(pSong);
}

void AudioManager::BirdSquawk()
{
	irrklang::ISound *pSnd = nullptr;
	int n = rand() % 5;

	switch (n)
	{
	case 0:
		pSnd = Instance().pSoundEng->play2D("../../../../reference/asset/angrybirds/audio/bird 02 collision a1.mp3", false, false, true);
		pSnd->drop(); // these are managed pointers: drop means you not adding to the ref counting
		break;
	case 1:
		pSnd = Instance().pSoundEng->play2D("../../../../reference/asset/angrybirds/audio/bird 02 collision a2.mp3", false, false, true);
		pSnd->drop();
		break;
	case 2:
		pSnd = Instance().pSoundEng->play2D("../../../../reference/asset/angrybirds/audio/bird 02 collision a3.mp3", false, false, true);
		pSnd->drop();
		break;
	case 3:
		pSnd = Instance().pSoundEng->play2D("../../../../reference/asset/angrybirds/audio/bird 02 collision a4.mp3", false, false, true);
		pSnd->drop();
		break;
	case 4:
	default:
		pSnd = Instance().pSoundEng->play2D("../../../../reference/asset/angrybirds/audio/bird 02 collision a5.mp3", false, false, true);
		pSnd->drop();
		break;
	}
}

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