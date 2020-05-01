#pragma once
#include "../Render/WindowGLFW.h"
#include "../Render/VertexDeclarationBuffer.h"
#include "../Shader/Shader.h"
#include "../Render/Mesh/Mesh.h"
#include "../Geometry/Transform.h"
#include "../Engine.h"
#include "../Shader/pipeline/Pipeline.h"
class RenderModule
{

private:
	
	bool initOpenGL() const;
	int w, h;
	GLuint program;
	WindowGLFW * window;
	GLuint mvp_location;
	glm::mat4 mvp;
	float lookAtval = 0.0f;
	Pipeline *  basicPipeline;
	std::unordered_map<std::string, Pipeline*> pipelines;

	void initRender();
public:
	RenderModule(WindowGLFW * w);
	~RenderModule();
	

	void setModelObjectConstants(const glm::mat4 model, const glm::vec4 color);
	
	bool attachShader(GLuint & shaderId);
	void useProgram();
	bool init();
	void render();
	void destroy();

	const glm::vec2 & getViewport()
	{
		return glm::vec2(w, h);
	}

	WindowGLFW * getCtxWindow();
};

