#pragma once

#include <ctime>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GLFWMain
{
public:
    GLFWMain(int major, int minor) : render_count(0) {
        glfwInit();
        InitWindow(800, 600);
        InitOpenGL(major, minor);
    }

    virtual ~GLFWMain() {
        glfwTerminate();
    }

    void RunRender() {
        while (!glfwWindowShouldClose(this->window)) {
            std::cout << std::time(nullptr) << " render_count: " << this->render_count << std::endl;
            OnKeyboardEvent(this->window);
            OnPrepareRender();

            // swap color buffers that is used to render
            glfwSwapBuffers(this->window);

            // poll IO events (keys pressed/released, mouse moved etc.)
            glfwPollEvents();
            this->render_count++;
        }
    }

    virtual void OnKeyboardEvent(GLFWwindow* window) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    virtual void OnWindowSizeChange(GLFWwindow* window, int width, int height) = 0;
    virtual void OnPrepareRender() = 0;

private:
    static void FrameBufferSizeCallback(GLFWwindow* window, int width, int height) {
        OnWindowSizeChange(window, width, height);
    }

    bool InitWindow(int width, int height) {
        // window creation and bind context
        this->window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
        if (this->window == NULL) {
            std::cout << "Failed to create GLFW window" << std::endl;
            return false;
        }
        glfwMakeContextCurrent(this->window);
        glfwSetFramebufferSizeCallback(this->window, FrameBufferSizeCallback);
        return true;
    }

    bool InitOpenGL(int major, int minor) {
        // use OpenGL 3.3 and core-profile api
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        // load all OpenGL function pointers
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return false;
        }
        return true;
    }

private:
    GLFWwindow* window;
    int render_count;
};
