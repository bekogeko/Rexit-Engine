#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>

#include "lib.h"

int main()
{
  if (!glfwInit())
  {
    std::cout << "Error: GLFW could not be initialized" << std::endl;
    return -1;
  }

  GLFWwindow *window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (window == NULL)
  {
    std::cout << "Error: GLFW window could not be created" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Error: GLAD could not be initialized" << std::endl;
    return -1;
  }

  while (!glfwWindowShouldClose(window))
  {

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  return 0;
}