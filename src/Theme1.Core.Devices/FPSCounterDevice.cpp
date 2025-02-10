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

#include "FPSCounterDevice.hpp"

#include "TextDrawDevice.hpp"

namespace ForradiaWorld
{
    void FPSCounterDevice::Update()
    {
        auto now = SDL_GetTicks(); // Get the current time in milliseconds

        // Update FPS count every second
        if (now > m_ticksLastUpdate + 1000)
        {
            m_fps = m_framesCount; // Store the number of frames rendered in the last second
            m_framesCount = 0; // Reset frame count for the new second
            m_ticksLastUpdate = now; // Update the last recorded time
        }

        m_framesCount++; // Increment the frame counter
    }

    void FPSCounterDevice::Render() const
    {
        // Draw the FPS counter on the screen at the top-right corner
        _<TextDrawDevice>().DrawString("FPS: " + std::to_string(m_fps), 0.95f, 0.05f);
    }

}
