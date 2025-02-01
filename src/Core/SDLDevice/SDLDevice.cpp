#include "SDLDevice.hpp"

namespace FW {
SDLDevice::SDLDevice()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    m_window = std::shared_ptr<SDL_Window>(
        SDL_CreateWindow(
            "Forradia World", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, 660, 660,
            SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP),
        SDLDeleter());

    if (m_window == nullptr) {
        std::cout << "Window could not be created. SDL Error: "
                  << std::string(SDL_GetError()) << std::endl;
        return;
    }

    m_renderer = std::shared_ptr<SDL_Renderer>(
        SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED),
        SDLDeleter());
}

void SDLDevice::ClearCanvas() const
{
    SDL_SetRenderDrawColor(m_renderer.get(), 0, 150, 255, 255);
    SDL_RenderClear(m_renderer.get());
}

void SDLDevice::PresentCanvas() const
{
    SDL_RenderPresent(m_renderer.get());
}
}
