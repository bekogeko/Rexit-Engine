#include "Window.h"
#include <iostream>

namespace Rexit
{
  Window::Window(unsigned int width, unsigned int height, const char *title)
  {
    // Initialize GLFW
    glfwInit();

    // Set GLFW window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create GLFW window
    m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (m_Window == NULL)
    {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return;
    }

    // Make the window's context current
    glfwMakeContextCurrent(m_Window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      std::cout << "Failed to initialize GLAD" << std::endl;
    }
  }

  Window::~Window()
  {
    glfwTerminate();
  }

  bool Window::ShouldClose()
  {
    return glfwWindowShouldClose(m_Window);
  }

  void Window::PollEvents()
  {
    glfwPollEvents();
  }

  void Window::SwapBuffers()
  {
    glfwSwapBuffers(m_Window);
  }

} // namespace Rexit