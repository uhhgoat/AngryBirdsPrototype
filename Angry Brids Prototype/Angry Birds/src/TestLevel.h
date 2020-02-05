#pragma once
#include "Level.h"

class SlingShot;
class WoodBlockMed;
class WoodBlockShort;
class WoodBlockLong;
class GlassBlockMed;
class GlassBlockShort;
class GlassBlockLong;
class StoneBlockMed;
class StoneBlockShort;
class StoneBlockLong;
class RedBird;
class YellowBird;
class WhiteBird;
class BlackBird;
class BlueBird;
class BigRedBird;
class GreenBird;


class TestLevel : public Level
{
public:
	bool BUILT;
	SlingShot *sH;
	WoodBlockShort *WBS;
	WoodBlockMed *WBM;
	WoodBlockLong *WBL;
	GlassBlockShort *GBS;
	GlassBlockMed *GBM;
	GlassBlockLong *GBL;
	StoneBlockShort *SBS;
	StoneBlockMed *SBM;
	StoneBlockLong *SBL;
	RedBird *rB;
	YellowBird* yB;
	WhiteBird* wB;
	BlackBird* blB;
	BlueBird* bB;
	BigRedBird* brB;
	GreenBird* gB;
	TestLevel(SlingShot* slingshot);

	TestLevel() = delete;
	TestLevel(const TestLevel&) = delete;
	TestLevel& operator=(const TestLevel&) = delete;

	~TestLevel();

	virtual void Update() override;


	virtual void SetLevel() override;

	virtual void ClearLevel() override;
};