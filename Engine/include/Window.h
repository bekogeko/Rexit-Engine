#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Rexit
{
  class Window
  {
  public:
    Window(unsigned int width, unsigned int height, const char *title);
    ~Window();

    bool ShouldClose();
    void MakeContextCurrent();

    void SwapBuffers();
    void PollEvents();

  private:
    GLFWwindow *m_Window;
  };

} // namespace Rexit
