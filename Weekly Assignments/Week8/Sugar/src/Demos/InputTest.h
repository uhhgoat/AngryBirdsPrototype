#ifndef INPUT_TEST_H
#define INPUT_TEST_H

class GameObject2D;
class SimpleRayCastCallBack;
class SimpleAABBQuery;
class ExplosionShrapnel;

void KeyboardTest();
void MouseTest(GameObject2D *pGobj);

void KeyboardResetBird(GameObject2D *pGobj);
void MouseApplyImpulse(GameObject2D *pGobj);

void CameraControls();

void AudioTests();

void MouseControlTest();
void RayCastQuery(SimpleRayCastCallBack* rccb);

void AABBQuery(SimpleAABBQuery* qcb);

void MouseWithTrailControl(YellowBird* pGobj);

void ClickExplosion(ExplosionShrapnel* pExp);

void DrawLines();


#endif