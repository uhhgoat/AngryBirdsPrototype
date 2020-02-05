#ifndef CAMERA_MAN_H
#define CAMERA_MAN_H

#include "Camera.h"

class CameraMan
{
private:
	static CameraMan *privInstance();
	CameraMan();
	~CameraMan();	

	// Data
	static CameraMan* ptrInstance;
	Camera *pCamOrthographic;
	Camera *pCamPerspective;

public:
	static Camera *GetCurrent(Camera::Type type);
	static void SetCurrentCamera(Camera *camera, Camera::Type type);
	
	static void Terminate() { delete ptrInstance; }




};

#endif