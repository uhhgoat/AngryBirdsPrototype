#ifndef _AudioManager
#define _AudioManager



namespace irrklang
{
	class ISoundEngine;
	class ISoundSource;
	class ISound;
}

class AudioManager
{
private:
	static AudioManager* ptrInstance;

	AudioManager();
	~AudioManager();
	AudioManager(const AudioManager&) = delete;
	AudioManager& operator=(const AudioManager&) = delete;
	AudioManager(const char* windowName, const int Width, const int Height);

	static AudioManager& Instance()
	{
		if (ptrInstance == nullptr)
			ptrInstance = new AudioManager();

		return *ptrInstance;
	}

	irrklang::ISoundEngine* pSoundEng;
	irrklang::ISound* pSong;


public:
	static void ToggleMusic();
	static void MusicOn();
	static void MusicOff();
	static void BirdSquawk();
	static void Snort();
	static void Glass();
	static void Stone();
	static void Wood();
	static void Win();
	static void Terminate();
};


#endif _AudioManager
