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

int main()
{
  std::cout << "Hello World" << std::endl;

  // Create window object
  Rexit::Window window(640, 480, "Hello World");

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

  while (!window.ShouldClose())
  {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // // render the triangle
    shaderProgram.Use();

    shaderProgram.SetUniformFloat("u_Color", 0.5f);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    window.SwapBuffers();

    window.PollEvents();
  }

  return 0;
}