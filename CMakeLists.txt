cmake_minimum_required(VERSION 3.12)
project(3D-Engine-OpenGL VERSION 0.1.0)

#set(CMAKE_CXX_COMPILER "/usr/bin/g++-9")

#include(CTest)
#enable_testing()

file(GLOB main_SRC CONFIGURE_DEPENDS "src/*.hpp" "src/*.cpp")
add_executable(3D-Engine-OpenGL ${main_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(3D-Engine-OpenGL glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(3D-Engine-OpenGL OpenGL::GL)

find_package(GLEW REQUIRED)
target_link_libraries(3D-Engine-OpenGL GLEW)