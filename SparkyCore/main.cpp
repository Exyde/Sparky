#include "src/graphics/window.h"
#include "src/maths/vec2.h"
#include "src/maths/vec3.h"


#define LOG(x) std::cout << x << std::endl;

int main() {


	using namespace sparky::maths;
	using namespace sparky::graphics;

	Window window(960, 540, "Core Sparky Engine");
	glClearColor(.8f, .1f, .2f, 1.f);

	//GLuint vao;
	//glGenVertexArrays(1, &vao);
	//glBindVertexArray(vao);

	vec2 a(1, 1);
	vec2 b(1, 766.5);
	vec2 c(2, 0);
	vec3 vec(15, 23, 30);

	vec.Log();

	a.Log();


	a.add(1);
	a.add(1.25, 3);

	a.Log();

	
	LOG("------------");



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