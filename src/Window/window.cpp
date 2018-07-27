//
// Created by angus on 7/27/18.
//

#include <iostream>
#include "window.h"

namespace gengine {
    namespace graphics {

        void windowResize(GLFWwindow* window, int width, int height);
        Window::Window(const char *title, int width, int height)
                : m_Title(title), m_Width(width), m_Height(height) {
            if (!init())
                glfwTerminate();
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
                    std::cout << "Failed to create GLFW Window" << std::endl;
                    return false;
                }
                glfwMakeContextCurrent(m_Window);
                glfwSetWindowSizeCallback(m_Window, windowResize);
            }
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
    }
}