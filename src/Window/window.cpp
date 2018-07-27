//
// Created by angus on 7/27/18.
//

#include <iostream>
#include "window.h"

namespace gengine {
    namespace graphics {

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
            }
            return true;
        }

        bool Window::closed() const {
            return glfwWindowShouldClose(m_Window) != 0;
        }

        void Window::update() const {
            glfwPollEvents();
            glfwSwapBuffers(m_Window);

        }
    }
}