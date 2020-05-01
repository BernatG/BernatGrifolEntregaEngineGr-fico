#pragma once
/*
Window Manager Class:
GLFWwindow * window; //Pointer to GLFW window.
width, height;
Name
*/
class WindowGLFW
{
private:
	GLFWwindow* window;
	uint32_t width, height;
	std::string windowName;


public:
	WindowGLFW(const uint32_t & w, const uint32_t & h, 
		const std::string & wName)  ;

	inline const uint32_t & getWidth();
	inline const uint32_t & getHeight();
	inline const std::string & getName();
	 GLFWwindow * getWindowGL();
	~WindowGLFW();
};

