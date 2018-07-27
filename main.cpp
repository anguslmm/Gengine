#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <src/Window/window.h>


int main(int, char**)
{
    using namespace gengine;
    using namespace graphics;
    Window window("Gengine", 800, 600);

    while (!window.closed())
    {
        window.update();
    }
    return 0;
}
