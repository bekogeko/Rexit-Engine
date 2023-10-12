cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(Rexit-Engine CXX)


find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

# set the project include and source directories
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)


# Set Source Files
set(PROJECT_SOURCES 
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c
    )


set(PROJECT_HEADERS 
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Rexit.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Shader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Window.h

  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/glad/glad.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/KHR/khrplatform.h
)


add_library(Rexit-Engine STATIC) 


# set_target_properties(Rexit-Engine PROPERTIES LINKER_LANGUAGE CXX)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(Rexit-Engine
  PRIVATE
    ${PROJECT_SOURCES}
  PUBLIC
    ${PROJECT_HEADERS}
)
target_link_libraries(Rexit-Engine
  PUBLIC
    glfw
    glm
    OpenGL::GL
    )