//
// Created by angus on 7/27/18.
//

#include <iostream>
#include "Window.h"

namespace gengine {
    namespace graphics {

        void windowResize(GLFWwindow* window, int width, int height);

        Window::Window(const char *title, int width, int height)
                : m_Title(title), m_Width(width), m_Height(height) {
            if (!init())
                glfwTerminate();
            for (int i=0; i<MAX_KEYS; i++)
            {
                m_Keys[i] = false;
            }
            for (int j=0; j<MAX_BUTTONS; j++)
            {
                m_MouseButtons[j] = false;
            }
        }

        Window::~Window() = default;

        bool Window::init() {
            if (!glfwInit()) {
                std::cout << "Failed to init GLFW" << std::endl;
                return false;
            } else {
                m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
                if (!m_Window) {
                    glfwTerminate();
                    std::cout << "Failed to create GLFW graphics" << std::endl;
                    return false;
                }
                glfwMakeContextCurrent(m_Window);
                glfwSetWindowSizeCallback(m_Window, windowResize);
                glfwSetWindowUserPointer(m_Window, this);
                glfwSetKeyCallback(m_Window, keyCallback);
                glfwSetCursorPosCallback(m_Window, mousePositionCallback);
                glfwSetMouseButtonCallback(m_Window, mouseButtonCallback);
            }

            if (glewInit() != GLEW_OK)
            {
                std::cout << "Could not initialize GLEW." << std::endl;
                return false;
            }

            std::cout << glGetString(GL_VERSION) << std::endl;
            return true;
        }

        bool Window::closed() const {
            return glfwWindowShouldClose(m_Window) != 0;
        }

        void Window::clear() const {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        }

        void Window::update() {
            glfwPollEvents();
            glfwSwapBuffers(m_Window);

        }

        void windowResize(GLFWwindow *window, int width, int height) {
            glViewport(0, 0, width, height);
        }

        void keyCallback(GLFWwindow* gwindow, int key, int scancode, int action, int mods) {
            auto window = (Window*)glfwGetWindowUserPointer(gwindow);
            window->setKey(key, action != GLFW_RELEASE);
        }

        void mouseButtonCallback(GLFWwindow* gwindow, int button, int action, int mods) {
            auto window = (Window*)glfwGetWindowUserPointer(gwindow);
            window->setMouseButton(button, action != GLFW_RELEASE);
        }

        void mousePositionCallback(GLFWwindow* gwindow, double xpos, double ypos) {
            auto window = (Window*)glfwGetWindowUserPointer(gwindow);
            window->setMousePosition(xpos, ypos);
        }

        bool Window::isKeyPressed(int keycode) {
            if (keycode >= MAX_KEYS)
                return false;
            return m_Keys[keycode];
        }

        bool Window::isMouseButtonPressed(int button) {
            if (button >= MAX_BUTTONS)
                return false;
            return m_MouseButtons[button];
        }

        void Window::setKey(int key, bool isPressed) {
            m_Keys[key] = isPressed;
        }

        void Window::setMouseButton(int button, bool isPressed){
            m_MouseButtons[button] = isPressed;
        }

        void Window::setMousePosition(double x, double y) {
            m_Mx = x;
            m_My = y;
        }
    }
}