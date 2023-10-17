#pragma once
#include "Application.h"

int main(int argc, char **argv)
{
  Rexit::Application *app = Rexit::CreateApplication();

  app->Run();

  delete app;
  return 0;
}