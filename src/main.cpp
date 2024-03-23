#include "headers.h"
#include "Examples/QuadExample.h"
#include "BaseExample.h"

#define WIDTH 1400
#define HEIGHT 1400

int main(int argv, char **args) {
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(
            WIDTH, HEIGHT, "OpenGL Example",
            nullptr, nullptr);

    if (!window) {
        printf("Could not create window!");
        return -1;
    }

    BaseExample *entry = new QuadExample();

    glfwMakeContextCurrent(window);
    glClearColor(0.5, 0.5, 0.5, 1);

    if (!entry->Init()) {
        return -1;
    }

    double prevTime = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        double currTime = glfwGetTime();
        entry->Update(float(currTime - prevTime));
        prevTime = currTime;

        glFlush();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}