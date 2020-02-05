#ifndef _Trajectory
#define _Trajectory

#include "Box2D.h"
#include "TrailFactory.h"

class Trajectory
{
public:
	Trajectory();
	~Trajectory() = default;
	Trajectory(const Trajectory&) = delete;
	Trajectory& operator=(const Trajectory&) = delete;

	void Trace(b2Vec2 initPos, b2Vec2 initVel);
	void Clear();
	void Cleanup();
	void Load();

private:
	TrailFactory pTrailFact;
	Trail** trails;
	int length = 30;

};


#endif _Trajectory