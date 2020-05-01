#include "precompiledHeader.h"
#include "Engine.h"
#include "Modules/RenderModule.h"
#include "Modules/JoseModule.h"
#include "Modules/BernatModule.h"




Engine& Engine::get()
{
	static Engine instance;
	return instance;
}

void Engine::SetCamera(Camera * newCamera)
{
	assert(newCamera);
	//delete cam;
	cam = newCamera;

}

RenderModule& Engine::getRender()
{
	assert(render);
	return *render;
	// TODO: insert return statement here
}

bool Engine::start()
{
	WindowGLFW*  window = new WindowGLFW(640, 480, "HELLO WORLD");
	render = new RenderModule(window);

	
	registerAllModules();
	
	
	if (!render->init())
	{
		return false;
	}
	moduleManager.start();

	return true;
}

void Engine::stop()
{
	moduleManager.destroy();
	render->destroy();
	delete render;
}

void Engine::doFrame()
{
	double t = glfwGetTime();
	while (!glfwWindowShouldClose(render->getCtxWindow()->getWindowGL())) {
		t = glfwGetTime() - t;
		update(t);
		assert(cam);
		render->render();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000) *t);
		t = glfwGetTime();
	
	}
}

void Engine::update(float dt)
{
	
	moduleManager.update(dt);


}

void Engine::setModelObjectConstants(const glm::mat4& model, const glm::vec4& color)
{
	getRender().setModelObjectConstants(model, color);
}

void Engine::registerAllModules()
{
	//JoseModule * module = new JoseModule;
	BernatModule* module = new BernatModule;
	
	moduleManager.registerModule(module);
//	moduleManager.stopModule(module);
}
