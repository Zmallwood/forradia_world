// Copyright 2025 Andreas Åkerberg

#include "MouseDevice.hpp"
#include "Theme0.Core.Assist/MouseButton.hpp"

namespace ForradiaWorld
{
    MouseDevice::MouseDevice()
        : m_leftButton(std::make_shared<MouseButton>())
        , m_rightButton(std::make_shared<MouseButton>())
    {
    }

    void MouseDevice::RegisterButtonPress(Uint8 button)
    {
        switch (button)
        {
        case SDL_BUTTON_LEFT:
            m_leftButton->RegisterPress();
            break;
        case SDL_BUTTON_RIGHT:
            m_rightButton->RegisterPress();
            break;
        }
    }

    void MouseDevice::RegisterButtonRelease(Uint8 button)
    {
        switch (button)
        {
        case SDL_BUTTON_LEFT:
            m_leftButton->RegisterRelease();
            break;
        case SDL_BUTTON_RIGHT:
            m_rightButton->RegisterRelease();
            break;
        }
    }
}
