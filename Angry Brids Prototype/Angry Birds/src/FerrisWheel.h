#pragma once
#include "Includes.h"
#include "EtherealBlock.h"
class FerrisWheel
{

private:

	Level * myLevel;

public:
	FerrisWheel(float x, float y);
	FerrisWheel() = default;
	~FerrisWheel();
	FerrisWheel(const FerrisWheel&) = delete;
	FerrisWheel& operator=(const FerrisWheel&) = delete;
	//JOINTS DEMO STUFF

	float posX;
	float posY;

	void SetLevel(Level* l);


	b2Body* groundBody;

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

	RegularPig* pig1;
	RegularPig* pig2;


	
};