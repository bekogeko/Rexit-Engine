cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)


# set the project name
project(RexitSandbox VERSION 0.1.0)

# set the project directory
set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

# set the project include and source directories
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)


set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
    )

set(PROJECT_HEADERS
    # ${PROJECT_INCLUDE_DIR}/lib.h
)

add_subdirectory(${PROJECT_DIR}/Engine)

# Instead of GLFW we should use our own windowing library
add_subdirectory(${PROJECT_DIR}/vendor/glfw)


# Instead of GLM we should use our own math library
# or a custom wrapper around GLM
add_subdirectory(${PROJECT_DIR}/vendor/glm)



add_executable(${PROJECT_NAME})
include_directories(${PROJECT_INCLUDE_DIR} ${PROJECT_DIR}/vendor/glfw/include ${PROJECT_DIR}/vendor/glm ${PROJECT_DIR}/Engine/include)

target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glm PUBLIC Rexit-Engine)


