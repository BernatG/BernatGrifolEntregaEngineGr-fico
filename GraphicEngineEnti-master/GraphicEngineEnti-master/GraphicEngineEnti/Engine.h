#pragma once
class RenderModule;
#include "Modules/moduleManager.h"
#include "Render/Camera/Camera.h"

class Engine
{

public:
	static Engine& get();
	void SetCamera(Camera * newCamera);
	const Camera * getCamera()
	{
		return cam;
	}
	RenderModule& getRender();
	inline const std::vector<Module*> & getActiveModules() { return  moduleManager.getActiveModules(); };

	bool start();
	void stop();
	void doFrame();
	void update(float dt); 
	void setModelObjectConstants(const glm::mat4 & model, const glm::vec4&  color);

private:
	RenderModule* render = nullptr;
	ModuleManager moduleManager;
	Camera * cam = nullptr;
	void registerAllModules();

};

