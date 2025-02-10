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
    * @class MouseButton
    * @brief Represents a mouse button and tracks its state (pressed, fired, released).
    */
    class MouseButton
    {
      public:
        /**
        * @brief Registers the press of the mouse button.
        * Sets the button's state to pressed and marks it as fired.
        */
        void RegisterPress();

        /**
        * @brief Registers the release of the mouse button.
        * Sets the button's state to released and marks it as such.
        */
        void RegisterRelease();

        /**
        * @brief Retrieves whether the mouse button has been fired (pressed).
        * @return True if the button has been pressed, false otherwise.
        */
        bool GetBeenFiredPickResult();

        /**
        * @brief Retrieves whether the mouse button has been released.
        * @return True if the button has been released, false otherwise.
        */
        bool GetBeenReleasedPickResult();

        /**
        * @brief Gets the current pressed state of the mouse button.
        * @return True if the button is currently pressed, false otherwise.
        */
        auto GetPressed() const
        {
            return m_pressed;
        }

      private:
        bool m_pressed { false }; /**< Tracks whether the button is currently pressed. */
        bool m_beenFired { false }; /**< Tracks whether the button has been pressed (fired). */
        bool m_beenReleased { false }; /**< Tracks whether the button has been released. */
    };

    /**
    * @class MouseDevice
    * @brief Represents a mouse device that manages the state of its buttons (left and right).
    */
    class MouseDevice
    {
      public:
        /**
        * @brief Constructor for initializing the mouse device with left and right buttons.
        */
        MouseDevice();

        /**
        * @brief Registers a button press event for a given mouse button.
        * @param button The SDL button code (e.g., SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT).
        */
        void RegisterButtonPress(Uint8 button);

        /**
        * @brief Registers a button release event for a given mouse button.
        * @param button The SDL button code (e.g., SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT).
        */
        void RegisterButtonRelease(Uint8 button);

        /**
        * @brief Gets the left mouse button.
        * @return A shared pointer to the left mouse button.
        */
        auto GetLeftButton() const
        {
            return m_leftButton;
        }

        /**
        * @brief Gets the right mouse button.
        * @return A shared pointer to the right mouse button.
        */
        auto GetRightButton() const
        {
            return m_rightButton;
        }

      private:
        std::shared_ptr<MouseButton> m_leftButton; /**< The left mouse button. */
        std::shared_ptr<MouseButton> m_rightButton; /**< The right mouse button. */
    };
}
