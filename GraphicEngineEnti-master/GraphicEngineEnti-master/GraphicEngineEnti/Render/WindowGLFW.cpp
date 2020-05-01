#include "precompiledHeader.h"
#include "WindowGLFW.h"



WindowGLFW::WindowGLFW(const uint32_t & w, const uint32_t & h, const std::string & wName)
{
	/*Danger*/
	
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
		//return false;
	}
	width = w; this->height = h; windowName = std::move(wName);
	window = glfwCreateWindow(w, h, wName.c_str(), NULL, NULL);
	
}

inline const uint32_t & WindowGLFW::getWidth()
{
	return width;
}

inline const uint32_t & WindowGLFW::getHeight()
{
	return height;
}

inline const std::string & WindowGLFW::getName()
{
	return windowName;
}

 GLFWwindow* WindowGLFW::getWindowGL()
{
	return window;
}

WindowGLFW::~WindowGLFW()
{
	glfwDestroyWindow(window);
}
