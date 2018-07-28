//
// Created by angus on 7/27/18.
//

#ifndef GENGINE_WINDOW_H
#define GENGINE_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_KEYS    1024
#define MAX_BUTTONS 32

namespace gengine { namespace graphics {

    static void keyCallback(GLFWwindow* gwindow, int key, int scancode, int action, int mods);
    static void mouseButtonCallback(GLFWwindow* gwindow, int button, int action, int mods);
    static void mousePositionCallback(GLFWwindow* gwindow, double xpos, double ypos);

    class Window
    {
    private:
        const char* m_Title;
        int m_Width, m_Height;
        GLFWwindow* m_Window;
        bool m_Closed;
        bool m_Keys[MAX_KEYS];
        bool m_MouseButtons[MAX_BUTTONS];
        double m_Mx, m_My;
    public:
        Window(const char* title, int width, int height);
        ~Window();
        void clear() const;
        void update();
        bool closed() const;
        inline int getWidth() const { return m_Width; }
        inline int getHeight() const { return m_Height; }

        void setKey(int key, bool isPressed);
        void setMouseButton(int button, bool isPressed);
        void setMousePosition(double x, double y);
        bool isKeyPressed(int keycode);
        bool isMouseButtonPressed(int button);
    private:
        bool init();
    };

}}

#endif //GENGINE_WINDOW_H
