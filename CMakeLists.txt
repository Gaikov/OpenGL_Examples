cmake_minimum_required(VERSION 3.27)
set(APP_NAME gl_examples)
project(${APP_NAME})

set(CMAKE_CXX_STANDARD 17)

find_package(DevIL REQUIRED)

find_package(GLFW3 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(./src)

add_executable(gl_examples
        src/main.cpp
        src/BaseExample.h
        src/Examples/QuadExample.cpp
        src/Examples/QuadExample.h
        src/headers.h
)

target_link_libraries(${APP_NAME}
        glfw
        ${OPENGL_LIBRARIES}
        ${IL_LIBRARIES}
        ${ILU_LIBRARIES}
        ${ILUT_LIBRARIES})
