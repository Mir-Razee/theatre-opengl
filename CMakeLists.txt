cmake_minimum_required(VERSION 3.2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)

project(3D-Movie-Theatre-OpenGL)

add_executable(theatre theatre.cpp "src/chair.cpp" "src/stair.cpp" "src/chairarm.cpp")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLU REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS})
target_link_libraries(theatre ${OPENGL_LIBRARIES} glut GLU GL)