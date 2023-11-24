#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace graphics {

#define MAX_KEYS 1024
#define MAX_MOUSEBUTTONS 32

	class Window
	{
	private:
		const char* m_Title;
		int m_Width, m_Height;
		GLFWwindow* m_Window;
		bool m_Closed;

		bool m_Keys[MAX_KEYS];
		bool m_MouseButtons[MAX_MOUSEBUTTONS];
		double mx, my;
	public:
		Window(const char* title, int width, int height);
		~Window();
		void clear() const;
		void update() const;
		bool closed();

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }

		bool keyPressed(unsigned int keycode) const;
		bool mouseButtonPressed(unsigned int button) const;
		void setMousePosition(double &x, double &y) const;
		void getMousePosition(double &x, double &y) const;
		void centerMousePosition();
		bool isMouseCentered();
		void hideMouse();
	private:
		bool init();
		friend static void window_resize(GLFWwindow* window, int width, int height);
		friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
		friend static void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos);
	};

}