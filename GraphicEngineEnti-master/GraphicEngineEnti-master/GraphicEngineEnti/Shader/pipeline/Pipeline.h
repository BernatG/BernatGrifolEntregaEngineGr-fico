#pragma once
#include "../Shader.h"
class Pipeline
{

	Shader vertex, fragment;
	GLuint pipelineID;


public:

	void setAttribDefinition(const std::string  & name,
		GLint size, GLenum type, GLboolean normalized, GLsizei stride,
		const GLvoid * pointer);
	Pipeline(const std::string & vertexUrl, const std::string & fragmentUrl);
	~Pipeline();

	inline const GLuint & getPipelineID()
	{
		return pipelineID;
	}
	
	void activatePipeline();
};

