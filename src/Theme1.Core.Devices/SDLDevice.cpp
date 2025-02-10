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

#include "SDLDevice.hpp"

namespace ForradiaWorld
{
    SDLDevice::SDLDevice()
    {
        // Initialize SDL with all subsystems enabled
        SDL_Init(SDL_INIT_EVERYTHING);

        // Create the application window with specific properties
        m_window = std::shared_ptr<SDL_Window>(
            SDL_CreateWindow(
                "Forradia World", // Window title
                SDL_WINDOWPOS_CENTERED, // Centered on screen (X position)
                SDL_WINDOWPOS_CENTERED, // Centered on screen (Y position)
                660, 660, // Window dimensions (width, height)
                SDL_WINDOW_SHOWN | // Show the window
                    SDL_WINDOW_RESIZABLE | // Allow resizing
                    SDL_WINDOW_MAXIMIZED | // Start maximized
                    SDL_WINDOW_FULLSCREEN_DESKTOP // Fullscreen mode
                ),
            SDLDeleter()); // Custom deleter for smart pointer cleanup

        // Check if window creation was successful
        if (!m_window)
        {
            std::cout << "Window could not be created. SDL Error: "
                      << std::string(SDL_GetError()) << std::endl;
            return;
        }

        // Create an accelerated renderer for the window
        m_renderer = std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED),
            SDLDeleter());

        // Check if renderer creation was successful
        if (!m_renderer)
        {
            std::cout << "Renderer could not be created. SDL Error: "
                      << std::string(SDL_GetError()) << std::endl;
            return;
        }
    }

    void SDLDevice::ClearCanvas() const
    {
        // Set the draw color to black
        SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);

        // Clear the screen with the set color
        SDL_RenderClear(m_renderer.get());
    }

    void SDLDevice::PresentCanvas() const
    {
        // Update the screen with the latest rendered frame
        SDL_RenderPresent(m_renderer.get());
    }
}
