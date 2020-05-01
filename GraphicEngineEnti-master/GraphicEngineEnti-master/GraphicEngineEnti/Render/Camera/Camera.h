#pragma once
#include "glm/glm.hpp"
#include"glm/gtc/constants.hpp"
#include "../../Geometry/Transform.h"

#define PI 3.14159265358979323846264338327950288
class Camera
{
	Transform transform;

	glm::vec3 target;
	//glm::vec3 up;

	glm::mat4 view;
	glm::mat4 proj;
	glm::mat4 view_proj;

	float fov_vertical_radians = (float)PI * 0.5f;
	float aspect_ratio = 1.0f;
	float z_min = 0.1f;
	float z_max = 100.f;

	void updateViewProjection();

public:

	Camera();
	void lookAt(glm::vec3 new_eye, glm::vec3 new_target, glm::vec3 new_up_aux = glm::vec3(0, 1, 0));
	void setProjectionParams(
		float fov_vertical_radians,
		float aspect_ratio,
		float z_min,
		float z_max
	);

	const glm::vec3& getPosition() const { return transform.getPosition(); }
	const glm::mat4& getView() const { return view; }
	const glm::mat4& getProjection() const { return proj; }
	const glm::mat4& getViewProjection() const { return view_proj; }
	float getAspectRatio() const { return aspect_ratio; }
	float getFov() const { return fov_vertical_radians; }
	float getZMin() const { return z_min; }
	float getZMax() const { return z_max; }
	const glm::vec3  getFront() {
		glm::mat4 inverted = glm::inverse(view);
		glm::vec3 normal = normalize(glm::vec3(inverted[2]));
		return normal;
	}

	Transform & getTransform() {
		return transform;
	}
};

