#pragma once
#include "../Modules/Module.h"
#include "../Render/Mesh/primitives.h"
#include "../Geometry/Transform.h"
#include "../Modules/RenderModule.h"
#include "../Render/Camera/Camera.h"

class JoseModule : public Module
{
private:
	Transform quad1,quad2,quad3,cubetransform;
	Camera * cam;
	GLFWwindow* window;
	glm::vec3 pos;
	glm::vec3 front = glm::vec3(0, 0, -1);

	glm::vec3 target = glm::vec3(0, 0, -1);
	float newAngle = 0.0f;
	float newPitch = 0.0f;
	bool canPress = true;
	int actualCamera = 0;
	std::vector<Camera*> cameras;
public:

		virtual void start() override;
		virtual void stop() override;
		virtual void renderDebug() override;
		virtual void update(float elapsed)override;

		void initCameras();
		void cameraController();


	JoseModule();
	~JoseModule();
};

