#ifndef _Wheel
#define _Wheel

#include "GameObject2D.h"


class Wheel : public GameObject2D
{
public:
	Wheel() = delete;
	virtual ~Wheel() = default;
	Wheel(const Wheel&) = delete;
	Wheel& operator=(const Wheel&) = delete;

	Wheel(float posx, float posy, float ang);


	
};


#endif _Wheel
