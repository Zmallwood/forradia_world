// Copyright 2025 Andreas Åkerberg

#include "KeyboardDevice.hpp"

namespace ForradiaWorld
{

    void KeyboardDevice::RegisterKeyPress(SDL_Keycode key)
    {
        m_pressedKeys.insert(key);
    }

    void KeyboardDevice::RegisterKeyRelease(SDL_Keycode key)
    {
        m_pressedKeys.erase(key);
    }

    bool KeyboardDevice::KeyIsPressed(SDL_Keycode key) const
    {
        return m_pressedKeys.contains(key);
    }

}
