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

#include "EngineDevice.hpp"

#include "KeyboardDevice.hpp"

#include "MouseDevice.hpp"

#include "SDLDevice.hpp"

#include "ScenesDevice.hpp"

namespace ForradiaWorld
{
    /*
============= CLASS: EngineDevice ============= */

    void EngineDevice::Run()
    {

        /*
Seed with time to get unique randomization in the game each game start. */

        srand(time(nullptr));

        /*
============= GAME LOOP ============= */

        while (m_running)
        {
            /*
Handle input. */

            PollEvents();

            /*
Update. */

            _<ScenesDevice>().UpdateCurrentScene();

            /*
Render. */

            _<SDLDevice>().ClearCanvas();
            _<ScenesDevice>().RenderCurrentScene();
            _<SDLDevice>().PresentCanvas();
        }
    }

    void EngineDevice::PollEvents()
    {
        SDL_Event event;

        /*
Go through all existing events. */

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {

                /*
The user has sent a quit event by closing the game window. */

            case SDL_QUIT:

                m_running = false;

                break;

                /*
A keyboard key has been pressed. */

            case SDL_KEYDOWN:

                _<KeyboardDevice>().RegisterKeyPress(event.key.keysym.sym);

                break;

                /*
A keyboard key has been released. */

            case SDL_KEYUP:

                _<KeyboardDevice>().RegisterKeyRelease(event.key.keysym.sym);

                break;

                /*
A mouse button has been pressed. */

            case SDL_MOUSEBUTTONDOWN:

                _<MouseDevice>().RegisterButtonPress(event.button.button);

                break;

                /*
A mouse button has been released */

            case SDL_MOUSEBUTTONUP:

                _<MouseDevice>().RegisterButtonRelease(event.button.button);

                break;
            }
        }
    }
}
