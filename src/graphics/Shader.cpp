//
// Created by angus on 7/29/18.
//

#include "Shader.h"

namespace gengine {
    namespace graphics {

        Shader::Shader(const char *vertexShaderPath, const char *fragmentShaderPath)
                : m_VertPath(vertexShaderPath), m_FragPath(fragmentShaderPath) {
            m_ShaderID = load();
        }

        Shader::~Shader() {
            glDeleteProgram(m_ShaderID);
        }

        GLuint Shader::load() {
            GLuint program = glCreateProgram();
            GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
            GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

            std::string vertSource = readFile(m_VertPath);
            std::string fragSource = readFile(m_FragPath);

            const char* cvertSource = vertSource.c_str();
            const char* cfragSource = fragSource.c_str();

            glShaderSource(vertex, 1, &cvertSource, NULL);
            glCompileShader(vertex);

            GLint result;
            glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
            if (result == GL_FALSE) {
                GLint length;
                glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
                std::vector<char> error(length);
                glGetShaderInfoLog(vertex, length, &length, &error[0]);
                std::cout << "Vertex shader compile error: " << &error[0] << std::endl;
                glDeleteShader(vertex);
                return 0;
            }

            glShaderSource(fragment, 1, &cfragSource, NULL);
            glCompileShader(fragment);

            glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
            if (result == GL_FALSE) {
                GLint length;
                glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
                std::vector<char> error(length);
                glGetShaderInfoLog(fragment, length, &length, &error[0]);
                std::cout << "Fragment shader compile error: " << &error[0] << std::endl;
                glDeleteShader(fragment);
                return 0;
            }

            glAttachShader(program, vertex);
            glAttachShader(program, fragment);

            glLinkProgram(program);
            glValidateProgram(program);

            glDeleteShader(vertex);
            glDeleteShader(fragment);
            return program;
        }

        void Shader::enable() const {
            glUseProgram(m_ShaderID);
        }

        void Shader::disable() const {
            glUseProgram(m_ShaderID);
        }

        GLint Shader::getUniformLocation(const GLchar *name) {
            glGetUniformLocation(m_ShaderID, name);
        }

        void Shader::setUniform1i(const GLchar *name, int value) {
            glUniform1i(getUniformLocation(name), value);
        }

        void Shader::setUniform1f(const GLchar *name, float value) {

            glUniform1f(getUniformLocation(name), value);

        }

        void Shader::setUniform2f(const GLchar *name, const math::Vec2 &vector) {

            glUniform2f(getUniformLocation(name), vector.x, vector.y);
        }

        void Shader::setUniform3f(const GLchar *name, const math::Vec3 &vector) {

            glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
        }

        void Shader::setUniform4f(const GLchar *name, const math::Vec4 &vector) {

            glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
        }

        void Shader::setUniformMat4(const GLchar *name, const math::Mat4 matrix) {

            glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);

        }
    }
}