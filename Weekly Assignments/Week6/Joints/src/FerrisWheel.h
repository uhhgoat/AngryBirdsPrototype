#pragma once
#include "Includes.h"
class FerrisWheel
{
public:
	FerrisWheel(b2World &world);
	~FerrisWheel();
	//JOINTS DEMO STUFF
	
	GlassBlockLong* pGround;

	WoodBlockShort* block1;
	WoodBlockShort* block2;
	WoodBlockShort* block3;
	WoodBlockShort* block4;
	WoodBlockShort* block5;
	WoodBlockShort* block6;

	EtherealBlock* eBlock1;
	EtherealBlock* eBlock2;
	EtherealBlock* eBlock3;

	KingPig* pig;
};