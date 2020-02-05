#ifndef _CarBodyOffroad
#define _CarBodyOffroad

#include "GameObject2D.h"

class CarBodyOffroad : public GameObject2D
{
public:
	CarBodyOffroad() = delete;
	virtual ~CarBodyOffroad() = default;
	CarBodyOffroad(const CarBodyOffroad&) = delete;
	CarBodyOffroad& operator=(const CarBodyOffroad&) = delete;

	CarBodyOffroad(float posx, float posy, float ang);


};

#endif CarCasualBody