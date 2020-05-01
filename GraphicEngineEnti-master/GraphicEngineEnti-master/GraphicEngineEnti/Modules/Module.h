#pragma once
//#include "precompiledHeader.h"
class Module
{
public:
	virtual void start() {}
	virtual void stop() {}
	virtual void renderDebug() {}
	virtual void update(float elapsed) {}
	virtual void destroy() {};
	
};



