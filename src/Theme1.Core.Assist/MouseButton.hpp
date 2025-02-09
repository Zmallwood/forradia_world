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
    /*
Represents a single button on the mouse. */

    class MouseButton
    {
      public:
        /*
Register the button as having been pressed. */

        void RegisterPress();

        /*
Register the button as having been released. */

        void RegisterRelease();

        /*
Returns the fired-state and resets this state. */

        bool GetBeenFiredPickResult();

        /*
Returns the released-state and resets this state. */

        bool GetBeenReleasedPickResult();

        auto GetPressed() const
        {
            return m_pressed;
        }

      private:
        bool m_pressed { false };
        bool m_beenFired { false };
        bool m_beenReleased { false };
    };
}
