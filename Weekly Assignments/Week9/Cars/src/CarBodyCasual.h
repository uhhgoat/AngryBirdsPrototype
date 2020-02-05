#ifndef _CarBodyCasual
#define _CarBodyCasual

#include "GameObject2D.h"

class CarBodyCasual : public GameObject2D
{
public:
	CarBodyCasual() = delete;
	virtual ~CarBodyCasual() = default;
	CarBodyCasual(const CarBodyCasual&) = delete;
	CarBodyCasual& operator=(const CarBodyCasual&) = delete;

	CarBodyCasual(float posx, float posy, float ang);


};

#endif CarCasualBody