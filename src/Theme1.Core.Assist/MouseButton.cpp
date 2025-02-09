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

#include "MouseButton.hpp"

namespace ForradiaWorld
{
    void MouseButton::RegisterPress()
    {
        /*
Set states corresponding to a mouse button press. */

        m_pressed = true;

        m_beenFired = true;
    }

    void MouseButton::RegisterRelease()
    {
        /*
Set states corresponding to a mouse button release. */

        m_pressed = false;

        m_beenReleased = true;
    }

    bool MouseButton::GetBeenFiredPickResult()
    {
        /*
Get state, reset it and return. */

        auto result = m_beenFired;

        m_beenFired = false;

        return result;
    }

    bool MouseButton::GetBeenReleasedPickResult()
    {
        /*
Get state, reset it and return. */

        auto result = m_beenReleased;

        m_beenReleased = false;

        return result;
    }
}
