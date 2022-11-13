#include "utils/glfwmain.hpp"
#include "utils/glshader.hpp"
#include "utils/glvertex.hpp"

class TriangleMain: public GLFWMain
{
public:
    TriangleMain() :
        GLFWMain(3, 3),
        vertices({
            // positions         // colors
            0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom left
            0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
        }) {
        GLShaders shaders;
        shaders.AddShader(GL_VERTEX_SHADER,
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "layout (location = 1) in vec3 aColor;\n"
            "out vec3 ourColor;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos, 1.0);\n"
            "   ourColor = aColor;\n"
            "}\0");
        shaders.AddShader(GL_FRAGMENT_SHADER,
            "#version 330 core\n"
            "out vec4 FragColor;\n"
            "in vec3 ourColor;\n"
            "void main()\n"
            "{\n"
            "   FragColor = vec4(ourColor, 1.0f);\n"
            "}\n\0");
        shaders.CompileProgram();
        shaders.UseProgram();

        this->vertices.Bind();
        this->vertices.SetBuffer(GL_STATIC_DRAW);
        this->vertices.SetAttribute(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); // position
        this->vertices.SetAttribute(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); // color
    }

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

private:
    GLShaders shaders;
    GLVertices<float> vertices;
};

int main()
{
    TriangleMain triangle;
    triangle.RunRender();
    return 0;
}