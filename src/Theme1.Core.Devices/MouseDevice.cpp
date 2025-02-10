/*
 * Copyright (c) 2025 Andreas Åkerberg.
 * All rights reserved.
 *
 * This file is part of Forradia World.
 *
 * Licensed under the MIT License (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://opensource.org/licenses/MIT
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "MouseDevice.hpp"

namespace ForradiaWorld
{
    void MouseButton::RegisterPress()
    {
        m_pressed = true; // Set the button to pressed.
        m_beenFired = true; // Mark that the button has been pressed (fired).
    }

    void MouseButton::RegisterRelease()
    {
        m_pressed = false; // Set the button to not pressed.
        m_beenReleased = true; // Mark that the button has been released.
    }

    bool MouseButton::GetBeenFiredPickResult()
    {
        auto result = m_beenFired; // Store the result of whether the button was fired.
        m_beenFired = false; // Reset the fired state for future checks.
        return result; // Return the result.
    }

    bool MouseButton::GetBeenReleasedPickResult()
    {
        auto result = m_beenReleased; // Store the result of whether the button was released.
        m_beenReleased = false; // Reset the released state for future checks.
        return result; // Return the result.
    }

    MouseDevice::MouseDevice()
        : m_leftButton(std::make_shared<MouseButton>())
        , m_rightButton(std::make_shared<MouseButton>())
    {
    }

    void MouseDevice::RegisterButtonPress(Uint8 button)
    {
        switch (button)
        {
        case SDL_BUTTON_LEFT: // If the left button is pressed.
            m_leftButton->RegisterPress(); // Register the press for the left button.
            break;

        case SDL_BUTTON_RIGHT: // If the right button is pressed.
            m_rightButton->RegisterPress(); // Register the press for the right button.
            break;
        }
    }

    void MouseDevice::RegisterButtonRelease(Uint8 button)
    {
        switch (button)
        {
        case SDL_BUTTON_LEFT: // If the left button is released.
            m_leftButton->RegisterRelease(); // Register the release for the left button.
            break;

        case SDL_BUTTON_RIGHT: // If the right button is released.
            m_rightButton->RegisterRelease(); // Register the release for the right button.
            break;
        }
    }

}
