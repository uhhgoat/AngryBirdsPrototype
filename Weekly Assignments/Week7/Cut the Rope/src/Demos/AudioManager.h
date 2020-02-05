// AudioManager
// Andre Berthiaume, April 2017

#ifndef _AudioManager
#define _AudioManager



namespace irrklang
{
	class ISoundEngine;
	class ISoundSource;
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

public:
	static void StartMusic();
	static void BirdSquawk();
	static void Terminate();
};


#endif _AudioManager
