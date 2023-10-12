#include "Shader.h"

#include <iostream>
#include <fstream>

namespace Rexit
{

  ShaderProgram::ShaderProgram()
  {
    m_ProgramId = glCreateProgram();
    m_UniformLocations = std::map<std::string, int>();
  }

  ShaderProgram::~ShaderProgram()
  {
    glDeleteProgram(m_ProgramId);
  }

  void ShaderProgram::LinkProgram()
  {
    glLinkProgram(m_ProgramId);

    // Check for linking errors
    int success;
    char infoLog[512];
    glGetProgramiv(m_ProgramId, GL_LINK_STATUS, &success);
    if (!success)
    {
      glGetProgramInfoLog(m_ProgramId, 512, NULL, infoLog);
      printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", infoLog);
    }
  }

  void ShaderProgram::Use()
  {
    glUseProgram(m_ProgramId);
  }

  void ShaderProgram::AttachShader(const char *shaderFile, ShaderType shaderType)
  {
    // Read shader file and get shader source
    std::string shaderSource = ReadShaderFile(shaderFile);

    // Convert shader source to const char*
    const char *shaderSourcePtr = shaderSource.c_str();

    // Create shader and compile
    unsigned int shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &shaderSourcePtr, NULL);
    glCompileShader(shaderId);

    // Check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
      printf("ERROR::SHADER::COMPILATION_FAILED\n%s\n", infoLog);
    }

    glAttachShader(m_ProgramId, shaderId);
    glDeleteShader(shaderId);
  }

  std::string ShaderProgram::ReadShaderFile(const char *shaderFile)
  {
    std::ifstream shaderFileStream(shaderFile);

    std::string shaderSource;
    std::string line;

    if (!shaderFileStream.is_open())
    {
      std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ\n";
    }

    while (std::getline(shaderFileStream, line))
    {
      shaderSource += line + "\n";
    }

    return shaderSource;
  }

  void ShaderProgram::SetUniformFloat(const std::string &uniformName, float value)
  {
    // Check if uniform location is already cached
    if (m_UniformLocations.find(uniformName) == m_UniformLocations.end())
    {
      // If not, get uniform location and cache it
      int uniformLocation = glGetUniformLocation(m_ProgramId, uniformName.c_str());
      m_UniformLocations[uniformName] = uniformLocation;
    }

    // Get uniform location from cache
    int uniformLocation = m_UniformLocations[uniformName];

    // Set uniform value
    glUniform1f(uniformLocation, value);
  }

} // namespace Rexit
