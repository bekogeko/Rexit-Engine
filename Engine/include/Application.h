#pragma once
#include "Window.h"

namespace Rexit
{

  class Application
  {
  public:
    Application(int width, int height, const char *title);
    virtual ~Application();

    void Run();

    virtual void Startup() = 0;
    virtual void Update() = 0;

  private:
    int m_Width;
    int m_Height;
    const char *m_Title;
    Window *m_Window;
  };

  Rexit::Application *CreateApplication();

} // namespace Rexit
