#include "window.h"

namespace sparky::graphics {

	void window_resize(GLFWwindow* window, int width, int height);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	Window::Window(int width, int height, const char* title) {
		this->m_width = width;
		this->m_height = height;
		this->m_title = title;
		if (!Init()) {
			glfwTerminate();
		}

		for (int i = 0; i < MAX_KEYS; i++) { m_keys[i] = false; };
		for (int i = 0; i < MAX_BUTTONS; i++) { m_mouseButtons[i] = false; };

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

		//Settings a lot of callbacks
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, this);
		glfwSetWindowSizeCallback(m_window, window_resize);

		glfwSetKeyCallback(m_window, key_callback);
		glfwSetMouseButtonCallback(m_window, mouse_button_callback);
		glfwSetCursorPosCallback(m_window, cursor_position_callback);


		//Glew part
		if (glewInit() != GLEW_OK) {
			std::cout << "Error initializing GLEW !" << std::endl;
			return false;
		}

		std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
		return true;
	}

	void Window::Clear() const {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::Update() {
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	bool Window::Closed() const {
		return glfwWindowShouldClose(m_window) == 1;
	}

	//Functions 
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		
		win->m_keys[key] = (action != GLFW_RELEASE);
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_mouseButtons[button] = (action != GLFW_RELEASE);
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_mouseX = xpos;
		win->m_mouseY = ypos;

	}


	void window_resize(GLFWwindow* window, int width, int height){
		glViewport(0, 0, width, height);
	}

	bool Window::isKeyPressed(unsigned int keyCode) const {

		//TODO : Log this !
		if (keyCode >= MAX_KEYS) return false;
		return m_keys[keyCode];
	}

	bool Window::isMouseButtonPressed(unsigned int buttonCode) const {

		//TODO : Log this !
		if (buttonCode >= MAX_BUTTONS) return false;
		return m_mouseButtons[buttonCode];
	}

	void Window::getMousePosition(double& x, double& y) const {
		x = m_mouseX;
		y = m_mouseY;
	}
}