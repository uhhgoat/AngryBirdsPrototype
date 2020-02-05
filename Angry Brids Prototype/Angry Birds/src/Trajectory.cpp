#include "Trajectory.h"
#include "Game.h"
#include "PixelToMeter.h"

Trajectory::Trajectory()
{
	trails = new Trail*[length];
	Load();
}

void Trajectory::Load()
{
	for (int i = 0; i < length; i++)
	{
		trails[i] = pTrailFact.Create(0, 0, 0, .4f);
		trails[i]->SetDrawSprite(false);
	}
}

void Trajectory::Trace(b2Vec2 initPos, b2Vec2 initVel)
{
	

	float timestep = 1.0f / 60;
	b2Vec2 a = Game::GetB2World()->GetGravity();

	b2Vec2 p = initPos;
	float t;
	for (int i = 0; i < length; i++)
	{
		t = 5 * i * timestep;

		p = initPos + t * initVel + t * t*0.5f * a;

		trails[i]->SetPosAng(MeterToPixel(p.x), MeterToPixel(p.y), 0);
		trails[i]->SetDrawSprite(true);
		//DebugMsg::out("tracing puff %d \n", i);
		
	}
}
void Trajectory::Clear()
{
	for (int i = 0; i < length; i++)
	{
		trails[i]->SetDrawSprite(false);
	}
}
void Trajectory::Cleanup()
{
	pTrailFact.RecallTrail();  // Recall the previous projected trail
}