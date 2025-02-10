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

#include "HeroDevice.hpp"

namespace ForradiaWorld
{
    void HeroDevice::MoveUp()
    {
        m_position.y--; // Move the hero one unit up (decrease Y coordinate)
    }

    void HeroDevice::MoveRight()
    {
        m_position.x++; // Move the hero one unit to the right (increase X coordinate)
    }

    void HeroDevice::MoveLeft()
    {
        m_position.x--; // Move the hero one unit to the left (decrease X coordinate)
    }

    void HeroDevice::MoveDown()
    {
        m_position.y++; // Move the hero one unit down (increase Y coordinate)
    }
}
