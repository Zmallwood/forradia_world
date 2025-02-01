#pragma once

namespace FW {
class KeyboardInput {
public:
    void RegisterKeyPress(SDL_Keycode key);
    void RegisterKeyRelease(SDL_Keycode key);
    bool KeyIsPressed(SDL_Keycode key) const;

private:
    std::set<SDL_Keycode> m_pressedKeys;
};
}
