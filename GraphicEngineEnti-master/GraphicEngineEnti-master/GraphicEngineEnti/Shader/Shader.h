#pragma once
#include <fstream>
class Shader
{
private:
	GLuint shaderId;
public:
	Shader();
	~Shader();
	bool init(const char * src, GLenum shaderType);
	void destroy();
	void activate() const;
	const GLuint& getId() const;
};

