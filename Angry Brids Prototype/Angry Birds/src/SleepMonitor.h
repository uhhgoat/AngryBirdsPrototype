#ifndef _SleepMonitor
#define _SleepMonitor

class b2Body;

class SleepMonitor
{
private:
	static SleepMonitor* ptrInstance;

	SleepMonitor();
	~SleepMonitor() = default;
	SleepMonitor(const SleepMonitor&) = delete;
	SleepMonitor& operator=(const SleepMonitor&) = delete;
	SleepMonitor(const char* windowName, const int Width, const int Height);

	static SleepMonitor& Instance()
	{
		if (ptrInstance == nullptr)
		{
			ptrInstance = new SleepMonitor();
		}

		return *ptrInstance;
	}

	int currAwakeCount;
	bool AllSleep;

	void privReportWakeState(b2Body* _pbod);

public:
	static void ReportWakeState(b2Body* _pbod);

	static bool isEveryoneAsleep();


	static void Terminate() { delete ptrInstance; }

};


#endif _SleepMonitor

