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
        SDL_Init(SDL_INIT_EVERYTHING);

        m_window = std::shared_ptr<SDL_Window>(
            SDL_CreateWindow(
                "Forradia World", SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED, 660, 660,
                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED),
            SDLDeleter());

        if (!m_window)
        {
            std::cout << "Window could not be created. SDL Error: "
                      << std::string(SDL_GetError()) << std::endl;

            return;
        }

        m_renderer = std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED),
            SDLDeleter());

        if (!m_renderer)
        {
            std::cout << "Renderer could not be created. SDL Error: "
                      << std::string(SDL_GetError()) << std::endl;

            return;
        }
    }

    void SDLDevice::ClearCanvas() const
    {
        SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);

        SDL_RenderClear(m_renderer.get());
    }

    void SDLDevice::PresentCanvas() const
    {
        SDL_RenderPresent(m_renderer.get());
    }

}
