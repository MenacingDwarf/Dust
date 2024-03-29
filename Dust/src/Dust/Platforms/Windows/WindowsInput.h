﻿#pragma once

#include "Dust/Input.h"

struct GLFWwindow;

namespace Dust
{
    class WindowsInput final : public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        std::pair<float, float> GetMousePositionImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
    private:
        GLFWwindow* GetWindow() const;
    };    
}
