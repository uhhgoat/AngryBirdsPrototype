#pragma once
#include "GameObject2D.h"
#include <list>
class MultiFixtureObject
{
public:
	std::list<GameObject2D*> objects;
};