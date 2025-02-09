// Copyright 2025 Andreas Åkerberg

#include "EngineDevice.hpp"
#include "Theme0.Core.Devices/KeyboardInputDevice.hpp"
#include "Theme0.Core.Devices/MouseInputDevice.hpp"
#include "Theme0.Core.Devices/SDLDevice.hpp"
#include "Theme0.Core.Devices/ScenesDevice.hpp"

namespace ForradiaWorld
{
    void EngineDevice::Run()
    {
        Randomize();

        while (m_running)
        {
            PollEvents();
            _<ScenesDevice>().UpdateCurrentScene();
            _<SDLDevice>().ClearCanvas();
            _<ScenesDevice>().RenderCurrentScene();
            _<SDLDevice>().PresentCanvas();
        }
    }

    void EngineDevice::Randomize() const
    {
        srand(time(nullptr));
    }

    void EngineDevice::PollEvents()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                m_running = false;
                break;
            case SDL_KEYDOWN:
                _<KeyboardInputDevice>().RegisterKeyPress(event.key.keysym.sym);
                break;
            case SDL_KEYUP:
                _<KeyboardInputDevice>().RegisterKeyRelease(event.key.keysym.sym);
                break;
            case SDL_MOUSEBUTTONDOWN:
                _<MouseInputDevice>().RegisterButtonPress(event.button.button);
                break;
            case SDL_MOUSEBUTTONUP:
                _<MouseInputDevice>().RegisterButtonRelease(event.button.button);
                break;
            }
        }
    }
}
