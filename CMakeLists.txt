cmake_minimum_required(VERSION 3.15)

# set the project name
project(Rexit)

# set the project directory
set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

# set the project include and source directories
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)


set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/lib.cpp
    ${PROJECT_SOURCE_DIR}/glad.c
# Headers
    ${PROJECT_INCLUDE_DIR}/lib.h
    )

# set(PROJECT_HEADERS
#     ${PROJECT_INCLUDE_DIR}/lib.h
# )



add_subdirectory(${PROJECT_DIR}/vendor/glfw)
add_subdirectory(${PROJECT_DIR}/vendor/glm)


include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} glfw glm)

