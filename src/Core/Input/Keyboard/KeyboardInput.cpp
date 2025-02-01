#include "KeyboardInput.hpp"

namespace FW {
void KeyboardInput::RegisterKeyPress(SDL_Keycode key)
{
    m_pressedKeys.insert(key);
}

void KeyboardInput::RegisterKeyRelease(SDL_Keycode key)
{
    m_pressedKeys.erase(key);
}

bool KeyboardInput::KeyIsPressed(SDL_Keycode key) const
{
    return m_pressedKeys.contains(key);
}
}
