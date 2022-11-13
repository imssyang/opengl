#pragma once

#include <iostream>
#include <vector>

template<typename T>
class GLVertices
{
public:
    GLVertices(const std::vector<T>& vertices)
        : vertices(vertices) {
        glGenVertexArrays(1, &this->vertices_id);
        glGenBuffers(1, &this->buffer_id);
    }

    virtual ~GLVertices() {
        glDeleteVertexArrays(1, &this->vertices_id);
        glDeleteBuffers(1, &this->buffer_id);
    }

    void Bind() {
        glBindVertexArray(this->vertices_id);
        glBindBuffer(GL_ARRAY_BUFFER, this->buffer_id);
    }

    static void Unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void SetBuffer(GLenum usage) {
        T arr[this->vertices.size()];
        std::copy(this->vertices.begin(), this->vertices.end(), arr);
        glBufferData(GL_ARRAY_BUFFER, sizeof(arr), arr, usage);
    }

    void SetAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {
        glVertexAttribPointer(index, size, type, normalized, stride, pointer);
        glEnableVertexAttribArray(index);
    }

private:
    std::vector<T> vertices;
    unsigned int vertices_id;
    unsigned int buffer_id;
};
