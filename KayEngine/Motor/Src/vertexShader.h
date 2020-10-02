#ifndef VERTEXSHADER_H
#define VERTEXSHADER_H

#include <glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "../../glm/glm.hpp"
#include "../../glm/gtc/matrix_transform.hpp"
#include "../../glm/gtc/type_ptr.hpp"

std::string vertexShader =
	"#version 330 core\n"
	"\n"
	"in vec4 position;\n"
	"in vec4 customColor;\n"
	"out vec4 color;\n"
	"uniform mat4 model;\n"

	"void main()"
	"{"
	
	"	gl_Position = model * vec4(position); \n"
	"	color = customColor;\n"
	"}\n"
	;
#endif VERTEXSHADER_H