#ifndef _WheelBig
#define _WheelBig

#include "GameObject2D.h"


class WheelBig : public GameObject2D
{
public:
	WheelBig() = delete;
	virtual ~WheelBig() = default;
	WheelBig(const WheelBig&) = delete;
	WheelBig& operator=(const WheelBig&) = delete;

	WheelBig(float posx, float posy, float ang);



};


#endif _WheelBig
