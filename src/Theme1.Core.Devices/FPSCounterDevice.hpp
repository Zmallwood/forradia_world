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
    * @class FPSCounterDevice
    * @brief Manages FPS (Frames Per Second) tracking and rendering.
    *
    * This class tracks the frame rate of the application and renders
    * the FPS count on the screen.
    */
    class FPSCounterDevice
    {
      public:
        /**
        * @brief Updates the FPS counter.
        *
        * This function tracks the number of frames rendered per second
        * and updates the FPS value accordingly.
        */
        void Update();

        /**
        * @brief Renders the FPS count on the screen.
        *
        * Displays the current FPS value as an on-screen text overlay.
        */
        void Render() const;

      private:
        int m_fps { 0 }; ///< Stores the calculated FPS value.
        int m_framesCount { 0 }; ///< Counts the number of frames rendered in the current second.
        int m_ticksLastUpdate { 0 }; ///< Stores the last time (in milliseconds) the FPS was updated.
    };
}
