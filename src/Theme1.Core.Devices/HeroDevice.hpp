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
    * @class HeroDevice
    * @brief Manages the movement and position of the hero (player) character.
    */
    class HeroDevice
    {
      public:
        /**
        * @brief Moves the hero up by one unit.
        */
        void MoveUp();

        /**
        * @brief Moves the hero right by one unit.
        */
        void MoveRight();

        /**
        * @brief Moves the hero down by one unit.
        */
        void MoveDown();

        /**
        * @brief Moves the hero left by one unit.
        */
        void MoveLeft();

        /**
        * @brief Gets the current position of the hero.
        * @return The current position as a Point.
        */
        auto GetPosition() const
        {
            return m_position;
        }

        /**
        * @brief Gets the last recorded movement time in ticks.
        * @return The time in ticks since the last movement.
        */
        auto GetTicksLastMovement() const
        {
            return m_ticksLastMovement;
        }

        /**
        * @brief Sets the last recorded movement time in ticks.
        * @param value The new tick value.
        */
        void SetTicksLastMovement(int value)
        {
            m_ticksLastMovement = value;
        }

        /**
        * @brief Gets the movement speed of the hero.
        * @return The movement speed as a float.
        */
        auto GetMovementSpeed() const
        {
            return m_movementSpeed;
        }

        /**
        * @brief Gets the hero's current movement destination.
        * @return The destination as a Point.
        */
        auto GetDestination() const
        {
            return m_destination;
        }

        /**
        * @brief Sets the hero's movement destination.
        * @param value The new destination point.
        */
        void SetDestination(Point value)
        {
            m_destination = value;
        }

      private:
        Point m_position { 50, 50 }; ///< The current position of the hero.
        Point m_destination { -1, -1 }; ///< The destination point for movement.
        int m_ticksLastMovement { 0 }; ///< Stores the last movement time in ticks.
        float m_movementSpeed { 3.0f }; ///< The speed of hero movement.
    };
}
