#include "utils/glfwmain.h"

class TriangleMain: public GLFWMain
{
public:
    TriangleMain() : GLFWMain(3, 3) {}

private:
    void OnWindowSizeChange(GLFWwindow* window, int width, int height) {
        // make sure the viewport matches the new window dimensions
        glViewport(0, 0, width, height);
    }

    void OnPrepareRender() {
        // clear screen's color buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //glBindVertexArray(VAO); // (options) no need to bind it every time for single VAO
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //glBindVertexArray(0); // (options) no need to unbind it every time
    }
};

int main()
{
    TriangleMain triangle;
    return 0;
}