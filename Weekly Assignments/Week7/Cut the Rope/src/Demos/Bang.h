// Bang.h
// AB 4/18
#ifndef _Bang
#define _Bang

#include "GameObject2D.h"

class Bang : public GameObject2D
{
public:
	Bang() = delete;
	~Bang() {};
	Bang(const Bang&) = delete;
	Bang& operator=(const Bang&) = delete;

	Bang(float posx, float posy, float ang);
};

#endif _Bang
