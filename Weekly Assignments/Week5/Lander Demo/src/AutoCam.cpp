#include "AutoCam.h"
AutoCam::AutoCam(GameObject2D* target1, GameObject2D* target2)
{
	this->target1 = target1;
	this->target2 = target2;
}
void AutoCam::Update()
{
	Camera *pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);

	Vect camPos;
	Vect lookAt;
	Vect camUp;
	Vect camRight;
	pCam->getPos(camPos);
	pCam->getLookAt(lookAt);
	pCam->getUp(camUp);
	pCam->getRight(camRight);

	

	camUp = Vect(0, 1, 0);
	b2Vec2 cen1 = b2Vec2(target1->posX, target1->posY);
	b2Vec2 cen2 = b2Vec2(target2->posX, target2->posY);
	b2Vec2 center = 0.5f * (cen2 + cen1);
	center.x -= pCam->getScreenWidth() / 2;
	center.y -= pCam->getScreenHeight() / 2;
	camPos.set(center.x, center.y, camPos.Z());
	lookAt.set(center.x, center.y, lookAt.Z());


	pCam->setOrientAndPosition(camUp, lookAt, camPos);

;

	float width = 1.15f* abs(cen2.x - cen1.x);
	float height = 1.15f* abs(cen2.y - cen1.y);
	if(height > width * (9.0f / 16.0f))
		width = height * (16.0f / 9.0f);
	else
		height = width * (9.0f / 16.0f);

	if(height > minHeight)
		pCam->setOrthographic(width/-2, width/2, height /-2, height /2, 1, 1000);


	
}