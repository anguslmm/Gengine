//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include <src/Window/window.h>
#include <iostream>


int main(int, char**)
{
    using namespace gengine;
    using namespace graphics;
    Window window("Gengine", 960, 540);
    glClearColor(0.2f, 0.2f, 0.7f, 1.0f);

    std::cout << glGetString(GL_VERSION) << std::endl;

    while (!window.closed())
    {
        std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
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
