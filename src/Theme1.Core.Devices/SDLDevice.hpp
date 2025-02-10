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

#pragma once

namespace ForradiaWorld
{
    /**
 * @class SDLDevice
 * @brief Manages SDL initialization, window, and rendering operations.
 */
    class SDLDevice
    {
      public:
        /**
        * @brief Constructs an SDLDevice, initializing SDL and creating a window and renderer.
        */
        SDLDevice();

        /**
        * @brief Clears the rendering canvas by filling it with a black color.
        */
        void ClearCanvas() const;

        /**
        * @brief Presents the current rendering canvas to the screen.
        */
        void PresentCanvas() const;

        /**
        * @brief Retrieves the SDL window.
        * @return A shared pointer to the SDL_Window.
        */
        auto GetWindow() const
        {
            return m_window;
        }

        /**
        * @brief Retrieves the SDL renderer.
        * @return A shared pointer to the SDL_Renderer.
        */
        auto GetRenderer() const
        {
            return m_renderer;
        }

      private:
        std::shared_ptr<SDL_Window> m_window; ///< Smart pointer holding the SDL window.
        std::shared_ptr<SDL_Renderer> m_renderer; ///< Smart pointer holding the SDL renderer.
    };
}
