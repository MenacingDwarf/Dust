#include "dustpch.h"
#include "WindowsInput.h"

#include "Dust/Application.h"

#include <GLFW/glfw3.h>

namespace Dust
{
    Input* Input::s_Instance = new WindowsInput();
    
    bool WindowsInput::IsKeyPressedImpl(int keycode)
    {
        const auto window = GetWindow();
        const auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int button)
    {
        const auto window = GetWindow();
        const auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        const auto window = GetWindow();
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return {(float)xpos, (float)ypos};
    }

    float WindowsInput::GetMouseXImpl()
    {
        return GetMousePosition().first;
    }

    float WindowsInput::GetMouseYImpl()
    {
        return GetMousePosition().second;
    }

    GLFWwindow* WindowsInput::GetWindow() const
    {
        return static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    }
}
