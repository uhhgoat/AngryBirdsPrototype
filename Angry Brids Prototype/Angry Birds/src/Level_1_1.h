#pragma once
#include "Level.h"

class RedBird;

class Platform;
class WoodBlockTiny;
class WoodBlockShort;
class WoodBlockLong;
class GlassBlockShort;

class RegularPig;


class Level_1_1 : public Level
{
public:
	bool BUILT;
	SlingShot *sH;

	Platform *pF1;
	Platform *pF2;
	Platform *pF3;
	Platform *pF4;

	WoodBlockTiny *WBT1;
	WoodBlockTiny *WBT2;
	WoodBlockTiny *WBT3;
	WoodBlockTiny *WBT4;

	WoodBlockShort *WBS1;
	WoodBlockShort *WBS2;
	WoodBlockShort *WBS3;

	WoodBlockLong *WBL1;
	WoodBlockLong *WBL2;
	WoodBlockLong *WBL3;
	WoodBlockLong *WBL4;
	WoodBlockLong *WBL5;

	GlassBlockShort *GBS1;
	GlassBlockShort *GBS2;

	RedBird *rB1;
	RedBird *rB2;
	RedBird *rB3;

	RegularPig *rP;


	Level_1_1() = delete;
	Level_1_1(const Level_1_1&) = delete;
	Level_1_1& operator=(const Level_1_1&) = delete;

	Level_1_1(SlingShot* slingshot);

	~Level_1_1();

	virtual void Update() override;


	virtual void SetLevel() override;

	virtual void ClearLevel() override;
};