#include "Windows.h"

GLFWwindow* innerRef;

Windows::Windows() {
	innerRef = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
}
Windows::Windows(int x, int y, const char* name){
	innerRef = glfwCreateWindow(x, y, name, NULL, NULL);
}
Windows::~Windows(){
	glfwTerminate();
}
int Windows::CheckCreateWindows() {
	if (!innerRef) {
		glfwTerminate();
		return -1;
	}
}
void Windows::CreateContextWindows() {
	glfwMakeContextCurrent(innerRef);
}

bool Windows::CheckGLFWwindowShouldClose(){
	return glfwWindowShouldClose(innerRef);
}

void Windows::SwapBuffersWindows(){
	glfwSwapBuffers(innerRef);
}
