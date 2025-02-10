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
    * @class Creature
    * @brief Represents a creature in the game.
    *
    * This class serves as a base class for all creatures, holding common attributes like type,
    * movement speed, and tracking of the last movement.
    */
    class Creature
    {
      public:
        /**
        * @brief Constructs a Creature object with a given name.
        * @param creatureName The name of the creature.
        */
        Creature(std::string_view creatureName);

        /**
        * @brief Destructor for the Creature class.
        *
        * The destructor is virtual to make the class polymorphic.
        */
        virtual ~Creature() { }

        /**
        * @brief Retrieves the type of the creature.
        * @return The creature's type identifier.
        */
        int GetType() const
        {
            return m_type;
        }

        /**
        * @brief Retrieves the ticks of the last movement.
        * @return The number of ticks since the last movement.
        */
        auto GetTicksLastMovement() const
        {
            return m_ticksLastMovement;
        }

        /**
        * @brief Sets the ticks of the last movement.
        * @param value The number of ticks to set.
        */
        void SetTicksLastMovement(int value)
        {
            m_ticksLastMovement = value;
        }

        /**
        * @brief Retrieves the movement speed of the creature.
        * @return The movement speed of the creature.
        */
        auto GetMovementSpeed() const
        {
            return m_movementSpeed;
        }

      private:
        int m_type { 0 }; ///< The type of the creature.
        int m_ticksLastMovement { 0 }; ///< The ticks of the last movement.
        float m_movementSpeed { 1.0f }; ///< The movement speed of the creature.
    };
}
