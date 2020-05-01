#pragma once
#include "Camera.h"
class CameraController
{
protected:
	Camera* cam;
	CameraController* controller;
public:
	void setCameraController(CameraController* Controller);
	virtual void updateCamera(float dt) = 0;
	void setCamera(Camera* cam);
	
};

