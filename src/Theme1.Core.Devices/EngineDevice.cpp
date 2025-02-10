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
#include "ScenesServiceDevice.hpp"
#include "FPSCounterDevice.hpp"

namespace ForradiaWorld
{
    void EngineDevice::Run()
    {
        srand(time(nullptr)); // Seed the random number generator with the current time.

        // Main game loop, runs while m_running is true.
        while (m_running)
        {
            PollEvents(); // Poll events (e.g., input events).

            _<ScenesServiceDevice>().UpdateCurrentScene(); // Update the current scene.
            _<FPSCounterDevice>().Update(); // Update FPS counter.

            _<SDLDevice>().ClearCanvas(); // Clear the canvas (prepare for new frame).
            _<ScenesServiceDevice>().RenderCurrentScene(); // Render the current scene to the canvas.
            _<FPSCounterDevice>().Render(); // Render the FPS counter to the canvas.
            _<SDLDevice>().PresentCanvas(); // Present the canvas (display the rendered content).
        }
    }

    void EngineDevice::PollEvents()
    {
        SDL_Event event; // SDL event object to store event data.

        // Loop to poll all available events in the event queue.
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                // SDL_QUIT event (user clicked close button, etc.), stop the game.
                m_running = false;
                break;

            case SDL_KEYDOWN:
                // Handle key press event.
                _<KeyboardDevice>().RegisterKeyPress(event.key.keysym.sym);
                break;

            case SDL_KEYUP:
                // Handle key release event.
                _<KeyboardDevice>().RegisterKeyRelease(event.key.keysym.sym);
                break;

            case SDL_MOUSEBUTTONDOWN:
                // Handle mouse button press event.
                _<MouseDevice>().RegisterButtonPress(event.button.button);
                break;

            case SDL_MOUSEBUTTONUP:
                // Handle mouse button release event.
                _<MouseDevice>().RegisterButtonRelease(event.button.button);
                break;
            }
        }
    }

}
