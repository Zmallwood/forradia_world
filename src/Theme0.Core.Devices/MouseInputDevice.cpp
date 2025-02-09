#include "MouseInputDevice.hpp"
#include "Theme0.Core.Assist/MouseButton.hpp"

namespace ForradiaWorld
{
    MouseInputDevice::MouseInputDevice()
        : m_leftButton(std::make_shared<MouseButton>())
        , m_rightButton(std::make_shared<MouseButton>())
    {
    }

    void MouseInputDevice::RegisterButtonPress(Uint8 button)
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

    void MouseInputDevice::RegisterButtonRelease(Uint8 button)
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
