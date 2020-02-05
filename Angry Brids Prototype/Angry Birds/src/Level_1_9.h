#pragma once
#include "Level.h"


class RedBird;

class StoneBlockMedThick;
class WoodBlockMedThick;
class WoodBlockSquare;
class WoodBlockShort;
class WoodBlockLong;
class GlassBlockTinySquare;
class GlassBlockMedThick;
class GlassBlockShort;

class RegularPig;


class Level_1_9 : public Level
{
public:
	bool BUILT;
	SlingShot *sH;

	StoneBlockMedThick *SBMT1;
	StoneBlockMedThick *SBMT2;
	StoneBlockMedThick *SBMT3;
	StoneBlockMedThick *SBMT4;
	StoneBlockMedThick *SBMT5;
	StoneBlockMedThick *SBMT6;

	WoodBlockMedThick *WBMT1;
	WoodBlockMedThick *WBMT2;
	WoodBlockMedThick *WBMT3;
	WoodBlockMedThick *WBMT4;
	WoodBlockMedThick *WBMT5;
	WoodBlockMedThick *WBMT6;

	WoodBlockSquare *WBSQ1;
	WoodBlockSquare *WBSQ2;
	WoodBlockSquare *WBSQ3;
	WoodBlockSquare *WBSQ4;

	WoodBlockShort *WBS1;
	WoodBlockShort *WBS2;
	WoodBlockShort *WBS3;
	WoodBlockShort *WBS4;
	WoodBlockShort *WBS5;
	WoodBlockShort *WBS6;
	WoodBlockShort *WBS7;

	WoodBlockLong *WBL1;
	WoodBlockLong *WBL2;
	WoodBlockLong *WBL3;
	WoodBlockLong *WBL4;
	WoodBlockLong *WBL5;

	GlassBlockTinySquare *GBTS1;
	GlassBlockTinySquare *GBTS2;
	GlassBlockTinySquare *GBTS3;
	GlassBlockTinySquare *GBTS4;

	GlassBlockMedThick *GBMT1;
	GlassBlockMedThick *GBMT2;

	GlassBlockShort *GBS1;
	GlassBlockShort *GBS2;

	RegularPig *rP1;
	RegularPig *rP2;
	RegularPig *rP3;

	RedBird *rB1;
	RedBird *rB2;
	RedBird *rB3;
	RedBird *rB4;


	Level_1_9(SlingShot* slingshot);

	Level_1_9() = delete;
	Level_1_9(const Level_1_9&) = delete;
	Level_1_9& operator=(const Level_1_9&) = delete;

	~Level_1_9();

	virtual void Update() override;


	virtual void SetLevel() override;

	virtual void ClearLevel() override;
};