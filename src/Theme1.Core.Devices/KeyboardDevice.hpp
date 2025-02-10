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
    * @class KeyboardDevice
    * @brief Manages keyboard input and tracks the state of pressed keys.
    */
    class KeyboardDevice
    {
      public:
        /**
        * @brief Registers a key press event.
        *
        * Adds the key to the list of currently pressed keys.
        * @param key The SDL keycode of the pressed key.
        */
        void RegisterKeyPress(SDL_Keycode key);

        /**
        * @brief Registers a key release event.
        *
        * Removes the key from the list of currently pressed keys.
        * @param key The SDL keycode of the released key.
        */
        void RegisterKeyRelease(SDL_Keycode key);

        /**
        * @brief Checks if a specific key is currently pressed.
        *
        * Checks if the key is in the list of pressed keys.
        * @param key The SDL keycode of the key to check.
        * @return True if the key is pressed, otherwise false.
        */
        bool KeyIsPressed(SDL_Keycode key) const;

      private:
        std::set<SDL_Keycode> m_pressedKeys; ///< A set to store currently pressed keys.
    };

}
