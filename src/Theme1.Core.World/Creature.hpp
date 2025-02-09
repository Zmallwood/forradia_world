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

    class Creature
    {
      public:
        Creature(std::string_view creatureName);

        virtual ~Creature() { }

        int GetType() const
        {
            return m_type;
        }
        auto GetTicksLastMovement() const
        {
            return m_ticksLastMovement;
        }
        void SetTicksLastMovement(int value)
        {
            m_ticksLastMovement = value;
        }
        auto GetMovementSpeed() const
        {
            return m_movementSpeed;
        }

      private:
        int m_type { 0 };
        int m_ticksLastMovement { 0 };
        float m_movementSpeed { 1.0f };
    };

}
