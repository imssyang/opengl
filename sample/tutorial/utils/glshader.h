#pragma once

#include <iostream>
#include <typeinfo>
#include <vector>
#include <glad/glad.h>

class GLShaders
{
public:
    GLShaders() {
       this->program_id = glCreateProgram();
    }

    virtual ~GLShaders() {
        glDeleteProgram(this->program_id);

        for (auto shader_id : this->shaders) {
            glDeleteShader(shader_id);
        }
    }

    bool AddShader(unsigned int shader_type, const char *shader_source) {
        unsigned int shader_id = glCreateShader(shader_type);
        glShaderSource(shader_id, 1, &shader_source, NULL);
        glCompileShader(shader_id);
        if (!CheckShaderStatus(shader_id)) {
            return false;
        }
        this->shaders.push_back(shader_id);
        return true;
    }

    bool CompileProgram() {
        for (auto shader_id : this->shaders)
            glAttachShader(this->program_id, shader_id);

        glLinkProgram(this->program_id);
        return CheckProgramStatus(this->program_id);
    }

    void UseProgram() {
        glUseProgram(this->program_id);
    }

    template<typename T>
    void setUniform(const char *name, std::vector<T> values) {
        int location = glGetUniformLocation(this->program_id, name.data());
        switch (values.size()) {
        case 1:
            if (typeid(T) == typeid(int))
                glUniform1i(location, values[0]);
            elif (typeid(T) == typeid(unsigned int))
                glUniform1ui(location, values[0]);
            elif (typeid(T) == typeid(float))
                glUniform1f(location, values[0]);
            elif (typeid(T) == typeid(double))
                glUniform1d(location, values[0]);
            else
                std::cout << "[1]: Unsupported type of value!" << std::endl;
            break;
        case 2:
            if (typeid(T) == typeid(int))
                glUniform2i(location, values[0], values[1]);
            elif (typeid(T) == typeid(unsigned int))
                glUniform2ui(location, values[0], values[1]);
            elif (typeid(T) == typeid(float))
                glUniform2f(location, values[0], values[1]);
            elif (typeid(T) == typeid(double))
                glUniform2d(location, values[0], values[1]);
            else
                std::cout << "[2]: Unsupported type of value!" << std::endl;
            break;
        case 3:
            if (typeid(T) == typeid(int))
                glUniform3i(location, values[0], values[1], values[2]);
            elif (typeid(T) == typeid(unsigned int))
                glUniform3ui(location, values[0], values[1], values[2]);
            elif (typeid(T) == typeid(float))
                glUniform3f(location, values[0], values[1], values[2]);
            elif (typeid(T) == typeid(double))
                glUniform3d(location, values[0], values[1], values[2]);
            else
                std::cout << "[3]: Unsupported type of value!" << std::endl;
            break;
        case 4:
            if (typeid(T) == typeid(int))
                glUniform4i(location, values[0], values[1], values[2], values[3]);
            elif (typeid(T) == typeid(unsigned int))
                glUniform4ui(location, values[0], values[1], values[2], values[3]);
            elif (typeid(T) == typeid(float))
                glUniform4f(location, values[0], values[1], values[2], values[3]);
            elif (typeid(T) == typeid(double))
                glUniform4d(location, values[0], values[1], values[2], values[3]);
            else
                std::cout << "[4]: Unsupported type of value!" << std::endl;
            break;
        default:
            std::cout << "Unsupported size of values!" << std::endl;
            break;
        }
    }

private:
    bool CheckShaderStatus(unsigned int shader_id) {
        int success;
        glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
        if (!success) {
            char errdesc[1024];
            glGetShaderInfoLog(shader_id, 1024, NULL, errdesc);
            std::cout << "SHADER_COMPILATION_ERROR: " << errdesc << std::endl;
            return false;
        }
        return true;
    }

    bool CheckProgramStatus(unsigned int program_id) {
        int success;
        glGetProgramiv(program_id, GL_LINK_STATUS, &success);
        if (!success) {
            char errdesc[1024];
            glGetProgramInfoLog(program_id, 1024, NULL, errdesc);
            std::cout << "PROGRAM_LINKING_ERROR: " << errdesc << std::endl;
            return false;
        }
        return true;
    }

private:
    unsigned int program_id;
    std::vector<unsigned int> shaders;
};
