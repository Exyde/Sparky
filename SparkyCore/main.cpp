#include "src/graphics/window.h"

int main() {

	sparky::graphics::Window window(960, 540, "Core Sparky Engine");

	glClearColor(.8f, .1f, .2f, 1.f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.Closed()) {
		window.Clear();

#if 1
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

#else 
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.Update();
	}

	return 0;
}