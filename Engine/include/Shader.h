#pragma once

#include <string>
#include <glad/glad.h>

namespace Rexit
{
  enum ShaderType
  {
    VERTEX = GL_VERTEX_SHADER,
    FRAGMENT = GL_FRAGMENT_SHADER
  };

  class ShaderProgram
  {
  public:
    ShaderProgram();
    ~ShaderProgram();

    

    void AttachShader(const char *shaderFile, ShaderType shaderType);

    void LinkProgram();

    void Use();

  private:
    unsigned int m_ProgramId;

    std::string ReadShaderFile(const char *shaderFile);
  };

} // namespace Rexit
