#pragma once
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace sparky::graphics {

	class Window {
	//Fields
	private:
		GLFWwindow* m_window;
		const char* m_title;
		int m_width, m_height;
		bool m_closed;

	//Methods
	public:
		Window(int width, int height, const char* name);
		~Window();
		void Clear() const;
		void Update();
		bool Closed() const;

		inline int getWidth() const		{ return m_width;  }
		inline int getHeight() const	{ return m_height; }

	private:
		bool Init();
	};
}