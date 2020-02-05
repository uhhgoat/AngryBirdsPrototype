#pragma once
#include "Level.h"

class SlingShot;
class FerrisWheel;
class HelmetPig;
class StoneCircle;
class WoodBlockLong;

class BlackBird;
class GreenBird;
class YellowBird;

class Level_FerrisWheel : public Level
{
public:
	bool BUILT;
	SlingShot *sH;

	BlackBird* bB;
	GreenBird* gB;
	YellowBird* yB;

	FerrisWheel *ferrisWheel;

	HelmetPig* hPig1;
	HelmetPig* hPig2;

	WoodBlockLong* pedestal1;
	WoodBlockLong* pedestal2;

	StoneCircle* rock1;

	WoodBlockLong* pedestal3;
	WoodBlockLong* pedestal4;

	StoneCircle* rock2;

	Level_FerrisWheel(SlingShot* slingshot);

	Level_FerrisWheel() = delete;
	Level_FerrisWheel(const Level_FerrisWheel&) = delete;
	Level_FerrisWheel& operator=(const Level_FerrisWheel&) = delete;

	~Level_FerrisWheel();

	virtual void Update() override;


	virtual void SetLevel() override;

	virtual void ClearLevel() override;
};