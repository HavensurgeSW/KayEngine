#ifndef FRAGMENTSHADER_H
#define FRAGMENTSHADER_H

#include <glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

std::string fragmentShader =
	"#version 330 core\n"
	"\n"
	"in vec4 color;"
	"out vec4 outColor;"
	"\n"
	"void main()"
	"{"
	"	outColor = color;\n"
	"}"
	"\n"
;


#endif !FRAGMENTSHADER_H