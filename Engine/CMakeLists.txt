cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(Rexit-Engine CXX)


find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

# set the project include and source directories
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)


# Set Source Files
set(PROJECT_SOURCES 
  PUBLIC
    ${PROJECT_SOURCE_DIR}/Shader.cpp
    ${PROJECT_SOURCE_DIR}/Window.cpp
    ${PROJECT_SOURCE_DIR}/Application.cpp
    ${PROJECT_SOURCE_DIR}/glad.c
    )


set(PROJECT_HEADERS 
  PUBLIC 
    ${PROJECT_INCLUDE_DIR}/Rexit.h 
    ${PROJECT_INCLUDE_DIR}/Shader.h
    ${PROJECT_INCLUDE_DIR}/EntryPoint.h
    ${PROJECT_INCLUDE_DIR}/Application.h
    ${PROJECT_INCLUDE_DIR}/Window.h

  PRIVATE
    ${PROJECT_INCLUDE_DIR}/glad/glad.h
    ${PROJECT_INCLUDE_DIR}/KHR/khrplatform.h
)


add_library(Rexit-Engine STATIC) 

target_sources(Rexit-Engine
  PUBLIC
    ${PROJECT_HEADERS}
  PRIVATE
    ${PROJECT_SOURCES})

include_directories(${PROJECT_INCLUDE_DIR})


target_link_libraries(Rexit-Engine
  PUBLIC
    glfw
    glm
    OpenGL::GL
    )