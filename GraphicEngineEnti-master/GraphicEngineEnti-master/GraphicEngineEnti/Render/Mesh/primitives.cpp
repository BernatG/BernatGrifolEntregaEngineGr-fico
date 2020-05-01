#include "precompiledHeader.h"
#include "primitives.h"
#include "../VertexDeclarationBuffer.h"

Mesh quad;
Mesh cube;
Mesh Sphere;
#define PI 	3.14159265358979323846
bool createQuad()
{

	std::vector<VtxPosColor> quadVertices;
	quadVertices.push_back({ -1.0f,  -1.0f,0.f, 0.f, 0.f, 1.f,1.0f }); //0
	quadVertices.push_back({ -1.0f, 1.0f,0.f, 1.f, 0.f, 0.f,1.0f });//1
	quadVertices.push_back({ 1.0, 1.0f,0.f, 0.f, 1.f, 0.f,1.0f });//2
	quadVertices.push_back({ 1.0f, -1.0f,0.f, 1.f, 1.f, 1.f,1.0f });//3


	std::vector<unsigned int>  idb = {
		0,1,2,
		0,2,3 };


	return quad.create(quadVertices.data(),
		quadVertices.size(),
		sizeof(VtxPosColor),
		idb,
		idb.size(), sizeof(unsigned int) * idb.size(),
		Mesh::eTopology::TRIANGLES);
}
bool createSphere()
{
	std::vector<VtxPosColor> sphereVertices;
	std::vector<unsigned int> idb;
	float sectorCount = 32.0f;
	float stackCount = 32.0f;

	float x, y, z, xy;                              // vertex position
	float sectorStep = 2 * PI / sectorCount;
	float stackStep = PI / stackCount;
	float sectorAngle, stackAngle;

	float radius = 1.0f;

	for (int i = 0; i <= stackCount; ++i)
	{
		stackAngle = PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
		xy = radius * cosf(stackAngle);             // r * cos(u)
		z = radius * sinf(stackAngle);              // r * sin(u)

		// add (sectorCount+1) vertices per stack
		// the first and last vertices have same position and normal, but different tex coords
		for (int j = 0; j <= sectorCount; ++j)
		{
			sectorAngle = j * sectorStep;           // starting from 0 to 2pi

			// vertex position (x, y, z)
			x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
			y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
			sphereVertices.push_back(VtxPosColor(x, y, z, 1, 1, 1, 1));

		}
	}


	int k1, k2;
	for (int i = 0; i < stackCount; ++i)
	{
		k1 = i * (sectorCount + 1);     // beginning of current stack
		k2 = k1 + sectorCount + 1;      // beginning of next stack

		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
		{
			// 2 triangles per sector excluding first and last stacks
			// k1 => k2 => k1+1
			if (i != 0)
			{
				idb.push_back(k1);
				idb.push_back(k2);
				idb.push_back(k1 + 1);
			}

			// k1+1 => k2 => k2+1
			if (i != (stackCount - 1))
			{
				idb.push_back(k1 + 1);
				idb.push_back(k2);
				idb.push_back(k2 + 1);
			}
		}
	}
	return Sphere.create(sphereVertices.data(),
		sphereVertices.size(),
		sizeof(VtxPosColor),
		idb,
		idb.size(), sizeof(unsigned int) * idb.size(),
		Mesh::eTopology::TRIANGLES);
}
bool createCube()
{
	std::vector<VtxPosColor> quadVertices = 
	{
		
		// front
		VtxPosColor(-1.0f, -1.0f,  1.0f,1.0f, 0.0f, 1.0f, 1.0f),
		VtxPosColor(1.0f, -1.0f,  1.0f, 0.0f, 1.0f,1.0f, 1.0f),
		VtxPosColor( 1.0,  1.0,  1.0, 0.0f,0.0f,0.1f, 1.0f),
		VtxPosColor (-1.0,  1.0,  1.0, 1.0f,1.0f,1.0f, 1.0f),
		// back
		VtxPosColor (-1.0, -1.0, -1.0, 1.0f,1.0f,1.0f, 1.0f),
		VtxPosColor(1.0, -1.0, -1.0,  1.0f,1.0f,1.0f, 1.0f),
		VtxPosColor( 1.0,  1.0, -1.0,  1.0f,1.0f,1.0f, 1.0f),
		VtxPosColor(-1.0,  1.0, -1.0, 1.0f,1.0f,1.0f, 1.0f)
	  };
	std::vector<unsigned int> idb = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};

	return cube.create(quadVertices.data(),
		quadVertices.size(),
		sizeof(VtxPosColor),
		idb,
		idb.size(), sizeof(unsigned int) * idb.size(),
		Mesh::eTopology::TRIANGLES);
	
}
bool createPrimitives()
{
	bool ok = true;
	ok &= createQuad();
	
	ok &= createCube();
	//ok &= createSphere();
	return  ok;
	
}




void destroyPrimitives()
{

}

void setObjRenderCtes(glm::mat4 world, glm::vec4 color)
{
	
}
