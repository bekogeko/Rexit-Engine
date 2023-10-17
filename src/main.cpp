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

class Sandbox : public Rexit::Application
{
private:
  unsigned int VAO, VBO;
  Rexit::ShaderProgram shaderProgram;

public:
  Sandbox() : Rexit::Application(640, 480, "Hello World") {}

  ~Sandbox()
  {

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
  }

  void Startup() override
  {
    shaderProgram.AttachShader("./shaders/simple.vs.glsl", Rexit::ShaderType::VERTEX);
    shaderProgram.AttachShader("./shaders/simple.fs.glsl", Rexit::ShaderType::FRAGMENT);
    shaderProgram.LinkProgram();
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // Bind VAO and VBO
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
  }
  void Update() override
  {
    shaderProgram.Use();
    shaderProgram.SetUniformFloat("u_Color", 0.5f);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
  }
};

Rexit::Application *Rexit::CreateApplication()
{
  return new Sandbox();
}