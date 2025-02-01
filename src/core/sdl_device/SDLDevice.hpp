#pragma once

namespace FW {
class SDLDevice {
public:
    SDLDevice();

    void ClearCanvas() const;
    void PresentCanvas() const;

private:
    std::shared_ptr<SDL_Window> m_window;
    std::shared_ptr<SDL_Renderer> m_renderer;
};
}
