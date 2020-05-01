#include "precompiledHeader.h"
#include "Shader.h"


Shader::Shader()
{
}


Shader::~Shader()
{
}

bool Shader::init(const char * src, GLenum shaderType)
{
	
	shaderId = glCreateShader(shaderType);
	if (!shaderId) return false;

	std::ifstream file(src);
	if (!file.is_open()) return false;
	std::string str((std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());
	const char *c_str = str.c_str();
	glShaderSource(shaderId, 1, &c_str, NULL);
	glCompileShader(shaderId);
	GLint vertex_compiled;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &vertex_compiled);
	if (vertex_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetShaderInfoLog(shaderId, 1024, &log_length, message);
		std::cout << message << std::endl;
	}
		return false;
}

void Shader::destroy()
{

}

const GLuint& Shader::getId() const
{
	return shaderId;
	// TODO: insert return statement here
}
