#include "Application.h"

namespace Rexit
{

  Application::Application(int width, int height, const char *title)
  {
    m_Height = height;
    m_Width = width;
    m_Title = title;
    m_Window = new Window(width, height, title);
  }

  Application::~Application()
  {
    delete m_Window;
  }

  void Application::Run()
  {
    m_Window->MakeContextCurrent();

    // Call the user-defined startup function
    Startup();

    while (!m_Window->ShouldClose())
    {

      // TODO: Move this to a renderer class
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      // TODO: Add ImGui

      // Call the user-defined update function
      Update();

      // This Update function should be called for every Layer
      // TODO: Add Layer system

      m_Window->SwapBuffers();
      m_Window->PollEvents();
    }
  }

} // namespace Rexit