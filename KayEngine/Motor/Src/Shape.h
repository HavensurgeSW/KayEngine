#ifndef SHAPE_H
#define SHAPE_H
#include "PrivateClass/Export.h"

#include "Entity2D.h"
#include "../Lib/glm/vec4.hpp"
class ENGINE_API Shape : public Entity2D
{
private:
public:
	Shape(Renderer *_renderer);
	Shape(Renderer *_renderer, Material* _material);
	~Shape();

};
#endif