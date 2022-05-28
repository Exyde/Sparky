#include "window.h"

namespace sparky::graphics {

	void windowResize(GLFWwindow* window, int width, int height);

	Window::Window(int width, int height, const char* title) {
		this->m_width = width;
		this->m_height = height;
		this->m_title = title;
		if (!Init()) {
			glfwTerminate();
		}
	}

	Window::~Window() {
		glfwTerminate();
	}

	bool Window::Init() {

		if (!glfwInit()) {
			std::cout << "Failed to initialize GLFW..." << std::endl;
			return false;
		}


		m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);

		if (!m_window) {
			glfwTerminate();
			std::cout << "Failed to create GLFW Window !" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_window);
		glfwSetWindowSizeCallback(m_window, windowResize);

		return true;
	}

	void Window::Clear() const {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::Update() {
		glfwPollEvents();
		//glfwGetFramebufferSize(m_window, &m_width, &m_height);
		glfwSwapBuffers(m_window);
	}

	bool Window::Closed() const {
		return glfwWindowShouldClose(m_window) == 1;
	}

	void windowResize(GLFWwindow* window, int width, int height){
		glViewport(0, 0, width, height);
	}
}