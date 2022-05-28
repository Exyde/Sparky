#include <GLFW/glfw3.h>
#include <iostream>

#include "src/graphics/window.h"

int main() {

	sparky::graphics::Window window(960, 540, "Core Sparky Engine");

	GLclampf r = 0.8;
	GLclampf g = 0.1;
	GLclampf b = 0.1;
	GLclampf a = .9;
	glClearColor(r, g, b, a);

	std::cout << glGetString(GL_VERSION);

	while (!window.Closed()) {

		std::cout << window.getWidth() << " , " << window.getHeight() << std::endl;;

		window.Clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.Update();
	}

	return 0;
}