#pragma once
#include "Includes.h"
class SeeSaw
{
public:
	SeeSaw(b2World &world);
	~SeeSaw();
	//JOINTS DEMO STUFF

	GlassBlockLong* pGround;

	WoodBlockShort* block1;
	WoodBlockShort* block2;

	EtherealBlock* pivot;
	WoodBlockLong* lever;


	KingPig* pig1;
	KingPig* pig2;
};