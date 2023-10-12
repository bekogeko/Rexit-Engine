cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(Rexit-Engine CXX)

# Set Source Files
set( PROJECT_SOURCES 
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shader.cpp

    )


set( PROJECT_HEADERS 
  PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Rexit.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Shader.h
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
