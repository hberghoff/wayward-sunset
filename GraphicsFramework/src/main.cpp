#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

extern "C" {_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001; }

auto errorCallback(int code, const char* errorMsg) -> void
{
	std::cout << "Error Code: " << code << " Msg: " << errorMsg << std::endl;
}

auto main(void) -> int
{
    if (!glfwInit())
    {
        return -1;
    }

	glfwSetErrorCallback(errorCallback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Wayward Sunset", nullptr, nullptr);

    if (window == nullptr)
    {
        std::cout << "Window failed to be made" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
		glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}