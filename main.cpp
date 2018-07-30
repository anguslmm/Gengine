//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include "src/graphics/Window.h"
#include "src/graphics/Shader.h"
#include "src/math/maths.h"
#include <iostream>
#include <src/utils/fileutils.h>

int main(int, char **) {
    using namespace gengine;
    using namespace graphics;
    using namespace math;
    Window window("Gengine", 960, 540);
    glClearColor(0.2f, 0.2f, 0.7f, 1.0f);

    GLfloat vertices[] =
            {
                    4, 3, 0,
                    12, 3, 0,
                    4, 6, 0,
                    4, 6, 0,
                    12, 6, 0,
                    12, 3, 0
            };

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);


    Shader shader("../src/shaders/basic.vert", "../src/shaders/basic.frag");
    shader.enable();

    Mat4 ortho = Mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

    Mat4 trans = Mat4::translation(Vec3(2, 2, 0));
    Mat4 rot = Mat4::rotation(45, Vec3(0, 0, 1));

    shader.setUniformMat4("pr_matrix", ortho);
//    shader.setUniformMat4("ml_matrix", rot);
    shader.setUniform2f("light_pos", Vec2(8, 4.5f));

    shader.setUniform4f("col", Vec4(0.0f, 1.0f, 0.0f, 1.0f));



    while (!window.closed()) {
        window.clear();
//        glBegin(GL_TRIANGLES);
//        glVertex2f(-0.5f, -0.5f);
//        glVertex2f(0.0f, 0.5f);
//        glVertex2f(0.5f, -0.5f);
//        glEnd();
        glDrawArrays(GL_TRIANGLES, 0, 6);
        window.update();
    }
    return 0;
}
