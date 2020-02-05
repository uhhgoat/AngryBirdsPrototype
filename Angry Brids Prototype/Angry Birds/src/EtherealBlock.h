#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class EtherealBlock : public GameObject2D
{
private:
public:
	EtherealBlock(float x, float y, float rot);
	EtherealBlock() = default;
	~EtherealBlock() = default;
	EtherealBlock(const EtherealBlock&) = delete;
	EtherealBlock& operator=(const EtherealBlock&) = delete;

};