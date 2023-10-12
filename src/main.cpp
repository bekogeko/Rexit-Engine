#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>

#include <Rexit.h>

float vertices[] = {
    -0.5f, -0.5f, 0.0f, // left
    0.5f, -0.5f, 0.0f,  // right
    0.0f, 0.5f, 0.0f    // top
};

// VAO and VBO
unsigned int VAO, VBO;
unsigned int program, vertexShader, fragmentShader;

int main()
{
  std::cout << "Hello World" << std::endl;

  if (!glfwInit())
  {
    std::cout << "Error: GLFW could not be initialized" << std::endl;
    return -1;
  }
  // Required for Mac OS X (At least on my machine)
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

  // Create vertex shader
  Rexit::ShaderProgram shaderProgram;

  // Attach shaders
  shaderProgram.AttachShader("./shaders/simple.vs.glsl", Rexit::ShaderType::VERTEX);
  shaderProgram.AttachShader("./shaders/simple.fs.glsl", Rexit::ShaderType::FRAGMENT);

  // Link Shader program
  shaderProgram.LinkProgram();

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  // Bind VAO and VBO
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

  glEnableVertexAttribArray(0);

  while (!glfwWindowShouldClose(window))
  {

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // // render the triangle
    shaderProgram.Use();

    shaderProgram.SetUniformFloat("u_Color", 0.5f);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}