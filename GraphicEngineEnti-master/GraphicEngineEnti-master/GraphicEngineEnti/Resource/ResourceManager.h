#pragma once
#include "Resource.h"
#include "../Render/Textures/Textures.h"
class ResourceManager
{

	std::unordered_map<std::string, Resource*> resources;

public:
	static ResourceManager& get();

	Texture * loadTexture(const std::string & fileName);
	

	const Resource * loadMesh(const std::string & fileName)
	{

	}
	ResourceManager();
	~ResourceManager();
};

