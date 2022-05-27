#include <GLFW/glfw3.h>
#include <iostream>

int main() {

	if (!glfwInit())
		std::cout << "Error loading GLFW" << std::endl;
	else
		std::cout << "Succes !" << std::endl;

	system("PAUSE");
	return 0;
}