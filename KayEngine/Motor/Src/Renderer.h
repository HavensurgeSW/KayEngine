#ifndef RENDERER_H
#define RENDERER_H

#define TAMVBO 14

#include "PrivateClass/Export.h"
#include "Windows.h"
#include <glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../../glm/glm.hpp"
#include "../../glm/gtc/matrix_transform.hpp"
#include "../../glm/gtc/type_ptr.hpp"
class ENGINE_API Renderer {
private:
	
	unsigned int _shaderProgram;
public:
	Renderer();
	~Renderer();
};
#endif // !RENDERER_H