#pragma once

#include "Dust/Core.h"
#include "Dust/Layer/Layer.h"

namespace Dust
{
    class KeyTypedEvent;
}

namespace Dust
{
    class WindowResizeEvent;
    class KeyReleasedEvent;
    class KeyPressedEvent;
    class MouseScrolledEvent;
    class MouseMovedEvent;
    class MouseButtonReleasedEvent;
    class MouseButtonPressedEvent;

    class DUST_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;

    private:
        bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleased(MouseButtonReleasedEvent& e);
        bool OnMouseMoved(MouseMovedEvent& e);
        bool OnMouseScrolled(MouseScrolledEvent& e);
        bool OnKeyPressed(KeyPressedEvent& e);
        bool OnKeyReleased(KeyReleasedEvent& e);
        bool OnKeyTyped(KeyTypedEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);

        void SetKeyDown(int KeyCode, bool IsDown);

    private:
        float m_Time = 0.0f;
    };
    
}
