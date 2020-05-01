#pragma once
class Transform
{

	glm::mat4  rot;
	glm::vec3  pos;
	glm::vec3 front;
	float scale = 1.0f;

public:
	Transform();
	glm::mat4 getRotation() const { return rot; }
	void setRotation(glm::mat4 new_rot) { rot = new_rot; }
	glm::vec3 getPosition() const { return pos; }
	void setPosition(glm::vec3 new_pos) { pos = new_pos; }
	void setPosition(float x, float y, float z) { pos = std::move(glm::vec3(x, y, z)); }
	void addPosition(glm::vec3 delta) { pos += delta; }
	void setScale(float new_scale) { scale = new_scale; }
	float getScale() const { return scale; }
	glm::vec3 getFront() const;
	glm::vec3 getLeft() const;
	glm::vec3 getUp() const;
	glm::mat4 asMatrix() const;
	void setEulerAngles(float yaw, float pitch, float roll);
	glm::vec3 getEulerAngles();


	void  yawPitchToVector(glm::vec3 & front, float yaw, float pitch) {
		this->front = glm::vec3(
			sinf(yaw) * cosf(-pitch),
			sinf(-pitch),
			cosf(yaw) * cosf(-pitch));
	}

	float getDeltaYawToAimTo(glm::vec3 p) const;
	bool isInCone(glm::vec3 p, float half_cone) const;



};

