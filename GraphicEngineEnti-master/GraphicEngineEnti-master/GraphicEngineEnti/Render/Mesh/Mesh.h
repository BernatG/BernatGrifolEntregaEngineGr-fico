#pragma once
class Mesh
{
public:
	enum eTopology {
		LINES = GL_LINES,
		TRIANGLES = GL_TRIANGLES,
		UNDEFINED
	};

	bool create(
		const void* vertices,
		uint32_t nvertexs,
		uint32_t new_bytes_per_vertex,
		std::vector<unsigned int> indices,
		uint32_t new_nindices,
		uint32_t new_bytes_per_index,
		eTopology new_topology	
	);
	void destroy() ;
	void render() const;
	void activate() const;
	void activateAndRender() const;
	

private:
	
	void* vb = nullptr;
	std::vector<unsigned int> ib;
	GLuint vbId, ibId,VAO;
	uint32_t bytes_per_vertex = 0;
	uint32_t bytes_per_index = 0;
	uint32_t nindices = 0;
	uint32_t nvertexs = 0;
	eTopology topology = UNDEFINED;
	
};

