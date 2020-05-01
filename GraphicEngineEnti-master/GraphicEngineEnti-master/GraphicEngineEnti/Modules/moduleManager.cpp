#include "precompiledHeader.h"
#include "moduleManager.h"


bool ModuleManager::isActive(Module* module){
	
	
	std::vector<Module*>::iterator it = std::find(activeModules.begin(), activeModules.end(),module);
	return it != activeModules.end();

}

void ModuleManager::registerModule(Module * module)
{
	activeModules.push_back(module);
}


void ModuleManager::startModule(Module * module)
{

	auto it = std::find(inactiveModules.begin(),
		inactiveModules.end(), module);
	if (it != inactiveModules.end())
	{
		activeModules.push_back(*it);
		inactiveModules.erase(it);
		return;
	}

	it = std::find(activeModules.begin(), activeModules.end(), module);

	if (it == activeModules.end())
	{
		module->start();
		registerModule(module);
	}
	


}
void ModuleManager::stopModule(Module * module)
{
	auto it = std::find(activeModules.begin(), activeModules.end(), module);

	if (it != activeModules.end())
	{
		(*it)->stop();
		inactiveModules.push_back(*it);
		activeModules.erase(it);
	}
	else
	{
		assert(0);
	}
}


void ModuleManager::start()
{
	for (auto & md : activeModules)
	{
		md->start();
	}
	for (auto & md : inactiveModules)
	{
		md->start();
	}
}

void ModuleManager::stop()
{
	for (auto & md : activeModules)
	{
		md->stop();
	}

	for (auto & md : inactiveModules)
	{
		md->stop();
	}
}

void ModuleManager::update(float elapsed)
{
	for (auto & md : activeModules)
	{
		md->update(elapsed);
	}
}

void ModuleManager::destroy()
{
	for (auto & md : activeModules)
	{
		md->destroy();
		delete md;
	}

	for (auto & md : inactiveModules)
	{
		md->destroy();
		delete md;
	}
}

void ModuleManager::render()
{
	for (auto & md : activeModules)
	{
		md->renderDebug();
	}

}

