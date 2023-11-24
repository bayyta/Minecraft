#include <Windows.h>

#include "window.h"

namespace graphics {

	Window::Window(const char* title, int width, int height)
		: m_Title(title), m_Width(width), m_Height(height)
	{
		if (!init())
			glfwTerminate();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW!" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			std::cout << "Failed to create GLFW window!" << std::endl;
			return false;
		}

		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(m_Window, (mode->width - m_Width) / 2, (mode->height - m_Height) / 2);

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_pos_callback);
		glfwSwapInterval(0);

		std::cout << "OpenGL:" << std::endl;
		std::cout << "  " << glGetString(GL_VERSION) << std::endl;
		std::cout << "  " << glGetString(GL_VENDOR) << std::endl;
		std::cout << "  " << glGetString(GL_RENDERER) << std::endl;

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Could not initialize GLEW!" << std::endl;
			return false;
		}

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		return true;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update() const
	{
		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console, BACKGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("OpenGL Error: %i\n", error);
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}

		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	bool Window::closed()
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	bool Window::keyPressed(unsigned int keycode) const
	{
		if (keycode >= MAX_KEYS)
		{
			std::cout << "Keycode out of bounds!" << std::endl;
			return false;
		}
		return m_Keys[keycode];
	}

	bool Window::mouseButtonPressed(unsigned int button) const
	{
		if (button >= MAX_MOUSEBUTTONS)
		{
			std::cout << "Mouse button out of bounds!" << std::endl;
			return false;
		}
		return m_MouseButtons[button];
	}

	void Window::setMousePosition(double &x, double &y) const
	{
		glfwSetCursorPos(m_Window, x, y);
	}

	void Window::getMousePosition(double &x, double &y) const
	{
		x = mx;
		y = my;
	}

	void Window::centerMousePosition()
	{
		glfwSetCursorPos(m_Window, m_Width / 2, m_Height / 2);
	}

	bool Window::isMouseCentered()
	{
		return mx == m_Width / 2 && my == m_Height / 2;
	}

	void Window::hideMouse()
	{
		glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	}

	void window_resize(GLFWwindow* window, int width, int height)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_Width = width;
		win->m_Height = height;
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_Keys[key] = action != GLFW_RELEASE;
	}

	void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_MouseButtons[button] = action != GLFW_RELEASE;
	}

	void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;
	}

}