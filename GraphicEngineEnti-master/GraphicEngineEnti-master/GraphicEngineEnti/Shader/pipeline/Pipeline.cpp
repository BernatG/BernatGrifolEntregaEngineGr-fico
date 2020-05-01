#include "precompiledHeader.h"
#include "Pipeline.h"




Pipeline::~Pipeline()
{
}
Pipeline::Pipeline(const std::string & vertexUrl, const std::string & fragmentUrl)
{
	vertex.init(vertexUrl.c_str(), GL_VERTEX_SHADER);
	fragment.init(fragmentUrl.c_str(), GL_FRAGMENT_SHADER);
	pipelineID = glCreateProgram();
	glAttachShader(pipelineID, vertex.getId());
	glAttachShader(pipelineID, fragment.getId());
	glLinkProgram(pipelineID);
	
}

void Pipeline::activatePipeline()
{
	glLinkProgram(pipelineID);
}

void Pipeline::setAttribDefinition(const std::string  & name,
	GLint size, GLenum type,
	GLboolean normalized, 
	GLsizei sizeofvertex,
	const GLvoid * pointer)
{
	GLuint posId = glGetAttribLocation(pipelineID, name.c_str());
	glEnableVertexAttribArray(posId);
	glVertexAttribPointer(posId
		, size, type, normalized,
		sizeofvertex, pointer);
}