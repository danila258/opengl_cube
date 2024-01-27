cmake_minimum_required(VERSION 3.20)
project(opengl_cube)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(OpenGL REQUIRED)

add_subdirectory(${CMAKE_SOURCE_DIR}/libs/glfw)
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/glm)

include_directories(${CMAKE_SOURCE_DIR}/libs/glad/include)
set(GLAD_SOURCES_C ${CMAKE_SOURCE_DIR}/libs/glad/src/glad.c)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SOURCES)

add_executable(${PROJECT_NAME} ${GLAD_SOURCES_C} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL::GL glfw glm::glm)
