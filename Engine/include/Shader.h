#pragma once

#include <string>
#include <map>

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

    void SetUniformFloat(const std::string &uniformName, float value);

  private:
    unsigned int m_ProgramId;

    // uniform location cache
    std::map<std::string, int> m_UniformLocations;

    std::string ReadShaderFile(const char *shaderFile);
  };

} // namespace Rexit
