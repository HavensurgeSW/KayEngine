#include "GameBase.h"
#include "fragmentShader.h"
#include "vertexShader.h"
GameBase::GameBase()
{
	glfwInit();

	windows = new Windows(800, 450, "KayEngine");
	render = new Renderer();
	quad = new Shape(render);
	tri = new Shape(render);
}
GameBase::~GameBase() 
{
	if (windows != NULL) 
		delete windows;
	if (quad != NULL)
		delete quad;
	if (tri != NULL)
		delete tri;
	if (render != NULL)
		delete render;
}
int GameBase::Init()
{ 
	if (!glfwInit() || windows == NULL)
		return -1;

	windows->CheckCreateWindows();
	windows->CreateContextWindows();
	render->GLEWInit();
	
	tri->InitShape(GL_TRIANGLES);

	render->SetShader(vertexShader, fragmentShader);

	tri->SetVertexsAttrib(render->GetShader());

	glUseProgram(render->GetShader());

	render->ClearShader();
	render->UnbindBuffer();

	//VALORES DE TESTEO
	float posX = 0;
	float posY = 0;
	float speed = 0.05f;
	const float posZ = 1;

	float rotX = 0;
	float rotY = 0;
	float rotZ = 0;
	float speedRotation = 0.05f;

	float scalX = 0;
	float scalY = 0;
	float scalZ = 0;
	float speedScale = 0.05f;

	float r = 1.0f;
	float g = 0.0f;
	float b = 0.0f;
	float a = 1.0f;
	bool enableSetSolidColor = true;

	while (!windows->CheckGLFWwindowShouldClose()){	
		if (enableSetSolidColor){
			tri->SetSolidColor(r, g, b, a, vertexShader, fragmentShader);
			if (glfwGetKey(windows->GetWindowsPtr(), GLFW_KEY_ENTER) == GLFW_PRESS) {
				r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				a = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			}
		}

		tri->Draw(GL_TRIANGLES, 3, render->GetShader(), windows, tri->GetInternalData().model);
		
		//Movement inputs
		if (glfwGetKey(windows->GetWindowsPtr(), GLFW_KEY_W) == GLFW_PRESS){
			posY = posY + speed;
			tri->SetPosition(posX, posY, posZ);
		}
		if (glfwGetKey(windows->GetWindowsPtr(), GLFW_KEY_S) == GLFW_PRESS){
			posY = posY - speed;
			tri->SetPosition(posX, posY, posZ);
		}
		if (glfwGetKey(windows->GetWindowsPtr(), GLFW_KEY_D) == GLFW_PRESS){
			posX = posX + speed;
			tri->SetPosition(posX, posY, posZ);
		}
		if (glfwGetKey(windows->GetWindowsPtr(), GLFW_KEY_A) == GLFW_PRESS){
			posX = posX - speed;
			tri->SetPosition(posX, posY, posZ);
		}

		//Rotations inputs
		if (glfwGetKey(windows->GetWindowsPtr(), GLFW_KEY_LEFT) == GLFW_PRESS){
			rotZ = rotZ + speedRotation;
			tri->SetRotationZ(rotZ);
		}
		if (glfwGetKey(windows->GetWindowsPtr(), GLFW_KEY_RIGHT) == GLFW_PRESS){
			rotZ = rotZ - speedRotation;
			tri->SetRotationZ(rotZ);
		}
	

		//Scaling inputs
		if (glfwGetKey(windows->GetWindowsPtr(), GLFW_KEY_UP) == GLFW_PRESS){
			scalX = scalX + speedScale;
			scalY = scalY + speedScale;
			scalZ = scalZ + speedScale;
			tri->SetScale(scalX, scalY, scalZ);
		}
		if (glfwGetKey(windows->GetWindowsPtr(), GLFW_KEY_DOWN) == GLFW_PRESS){
			scalX = scalX - speedScale;
			scalY = scalY - speedScale;
			scalZ = scalZ - speedScale;
			tri->SetScale(scalX, scalY, scalZ);
		}
		
		glfwPollEvents();
	}

	glDeleteProgram(render->GetShader());
	glfwTerminate();
	return 0; 
}