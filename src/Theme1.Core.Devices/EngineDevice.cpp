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
