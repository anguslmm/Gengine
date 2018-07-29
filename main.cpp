//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include "src/graphics/Window.h"
#include "src/math/maths.h"
#include <iostream>


int main(int, char**)
{
    using namespace gengine;
    using namespace graphics;
    using namespace math;
    Window window("Gengine", 960, 540);
    glClearColor(0.2f, 0.2f, 0.7f, 1.0f);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    Mat4 position = Mat4::translation(Vec3(2, 3, 4));
    while (!window.closed())
    {
        window.clear();
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.0f,  0.5f);
        glVertex2f( 0.5f, -0.5f);
        glEnd();
        window.update();
    }
    return 0;
}
