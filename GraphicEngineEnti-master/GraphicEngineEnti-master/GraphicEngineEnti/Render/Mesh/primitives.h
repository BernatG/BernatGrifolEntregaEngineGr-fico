#pragma once
#include "Mesh.h"


bool createPrimitives();
void destroyPrimitives();
void setObjRenderCtes(glm::mat4 world, glm::vec4 color = glm::vec4(1));

extern Mesh quad;



