#pragma once
class SlingShot;
class Level
{
protected:
	int numPigs;
public:

	Level() = delete;
	~Level() {};
	Level(const Level&) = delete;
	Level& operator=(const Level&) = delete;

	Level(SlingShot* slingshot) { slingshot; };
	virtual void Update() {};

	virtual void SetLevel() {};

	virtual void ClearLevel() {};

	virtual void ReportDeadPig();

	virtual void ReportAddPig();
};