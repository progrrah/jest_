cmake_minimum_required(VERSION 3.25)
project(openglprojects LANGUAGES C CXX)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(X11 REQUIRED)

add_executable(openglprojects src/main.cpp)
target_link_libraries(openglprojects OpenGL::GL GLUT::GLUT GLEW::GLEW X11::X11)

set(GREAT_EXAMPLES_SRC GREAT_EXAMPLES/abgr.c GREAT_EXAMPLES/bitfont.c GREAT_EXAMPLES/cube.c GREAT_EXAMPLES/blender.c
    GREAT_EXAMPLES/dinoshade.cpp)
set(GREAT_EXAMPLES_NAME abgr bitfont cube blender dinoshade)

list(GET GREAT_EXAMPLES_SRC 0 EX1)
list(GET GREAT_EXAMPLES_NAME 0 EX1_NAME)

list(GET GREAT_EXAMPLES_SRC 1 EX2)
list(GET GREAT_EXAMPLES_NAME 1 EX2_NAME)

list(GET GREAT_EXAMPLES_SRC 2 EX3)
list(GET GREAT_EXAMPLES_NAME 2 EX3_NAME)

list(GET GREAT_EXAMPLES_SRC 3 EX4)
list(GET GREAT_EXAMPLES_NAME 3 EX4_NAME)

list(GET GREAT_EXAMPLES_SRC 4 EX5)
list(GET GREAT_EXAMPLES_NAME 4 EX5_NAME)

# add_executable(${EX1_NAME} ${EX1})
# target_link_libraries(${EX1_NAME} OpenGL::GL GLUT::GLUT GLEW::GLEW GLUT)

# add_executable(${EX2_NAME} ${EX2})
# target_link_libraries(${EX2_NAME} OpenGL::GL GLUT::GLUT GLEW::GLEW)

# add_executable(${EX3_NAME} ${EX3})
# target_link_libraries(${EX3_NAME} OpenGL::GL GLUT::GLUT GLEW::GLEW)

# # add_executable(${EX4_NAME} ${EX4})
# target_link_libraries(${EX4_NAME} OpenGL::GL GLUT::GLUT GLEW::GLEW)
# add_executable(${EX5_NAME} ${EX5})
add_compile_options(-Wall -ggdb -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm)