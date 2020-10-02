#ifndef ENTITY_H
#define ENTITY_H

#include "../Lib/glm/vec4.hpp"
#include "../Lib/glm/vec3.hpp"
#include "../Lib/glm/vec2.hpp"
#include "../Lib/glm/mat4x4.hpp"
#include "../Lib/glm/ext/matrix_transform.hpp"
#include "../Lib/glm/ext/matrix_clip_space.hpp"
#include "../Lib/glm/ext/scalar_constants.hpp"
#include "PrivateClass/Export.h"
#include "Renderer.h"



#define ENTITY_2DIMENTIONS 1
#define ENTITY_3DIMENTIONS 2
//using namespace glm;

struct ENGINE_API Transform{
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};
struct ENGINE_API InternalData{
	glm::mat4 model;
	glm::mat4 translate;
	glm::mat4 rotateX;
	glm::mat4 rotateY;
	glm::mat4 rotateZ;
	glm::mat4 scale;
};
class ENGINE_API Entity{
protected:
	Renderer* renderer;
public:
	
};
#endif