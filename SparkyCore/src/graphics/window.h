#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace sparky::graphics {

#define MAX_KEYS	1024
#define MAX_BUTTONS	32

	class Window {
	//Fields
	private:
		GLFWwindow* m_window;
		const char* m_title;
		int m_width, m_height;
		bool m_closed;

		//Inputs
		bool m_keys[MAX_KEYS];
		bool m_mouseButtons[MAX_BUTTONS];
		double m_mouseX, m_mouseY;


	//Methods
	public:
		Window(int width, int height, const char* name);
		~Window();
		void Clear() const;
		void Update();
		bool Closed() const;

		inline int getWidth() const		{ return m_width;  }
		inline int getHeight() const	{ return m_height; }

		bool isKeyPressed				(unsigned int keyCode) const;
		bool isMouseButtonPressed		(unsigned int buttonCode) const ;
		void getMousePosition			(double& x, double& y) const;


	private:
		bool Init();
		//GLFW Callbacks
		friend static void key_callback					(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback		(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback		(GLFWwindow* window, double xpos, double ypos);
	};
}