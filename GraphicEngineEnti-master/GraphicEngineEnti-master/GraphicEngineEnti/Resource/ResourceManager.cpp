#include "precompiledHeader.h"
#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
}

ResourceManager& ResourceManager::get()
{
	static ResourceManager instance;
	return instance;
}
ResourceManager::~ResourceManager()
{
}

Texture * ResourceManager::loadTexture(const std::string & fileName)
{
	if (resources.find(fileName) != resources.end()) {
		return (Texture*) resources[fileName.c_str()];
	}
	Texture * rsc = new Texture;
	if (!rsc->create(fileName))
		return nullptr;

	resources[fileName.c_str()] = rsc;
	return rsc;
}