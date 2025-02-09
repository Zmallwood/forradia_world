// Copyright 2025 Andreas Åkerberg

#include "EngineDevice.hpp"

#include "KeyboardDevice.hpp"

#include "MouseDevice.hpp"

#include "SDLDevice.hpp"

#include "ScenesDevice.hpp"

namespace ForradiaWorld
{

    void EngineDevice::Run()
    {
        Randomize();

        /*\
=================== GAME LOOP ====================*/

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

                _<KeyboardDevice>().RegisterKeyPress(event.key.keysym.sym);

                break;

            case SDL_KEYUP:

                _<KeyboardDevice>().RegisterKeyRelease(event.key.keysym.sym);

                break;

            case SDL_MOUSEBUTTONDOWN:

                _<MouseDevice>().RegisterButtonPress(event.button.button);

                break;

            case SDL_MOUSEBUTTONUP:

                _<MouseDevice>().RegisterButtonRelease(event.button.button);

                break;
            }
        }
    }

}
