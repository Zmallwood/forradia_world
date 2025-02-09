#include "KeyboardInputDevice.hpp"

namespace ForradiaWorld
{
    void KeyboardInputDevice::RegisterKeyPress(SDL_Keycode key)
    {
        m_pressedKeys.insert(key);
    }

    void KeyboardInputDevice::RegisterKeyRelease(SDL_Keycode key)
    {
        m_pressedKeys.erase(key);
    }

    bool KeyboardInputDevice::KeyIsPressed(SDL_Keycode key) const
    {
        return m_pressedKeys.contains(key);
    }
}
