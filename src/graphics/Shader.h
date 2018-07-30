//
// Created by angus on 7/29/18.
//

#ifndef GENGINE_SHADER_H
#define GENGINE_SHADER_H

#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <src/math/maths.h>
#include "../utils/fileutils.h"

namespace gengine {
    namespace graphics {
        class Shader {
        private:
            GLuint m_ShaderID;
            const char* m_VertPath;
            const char* m_FragPath;
        public:
            Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
            ~Shader();

            GLint getUniformLocation(const GLchar* name);

            void setUniform1i(const GLchar* name, int value);

            void setUniform1f(const GLchar* name, float value);
            void setUniform2f(const GLchar* name, const math::Vec2& vector);
            void setUniform3f(const GLchar* name, const math::Vec3& vector);
            void setUniform4f(const GLchar* name, const math::Vec4& vector);

            void setUniformMat4(const GLchar* name, const math::Mat4 matrix);

            void enable() const;
            void disable() const;
        private:
            GLuint load();
        };
    }
}


#endif //GENGINE_SHADER_H
