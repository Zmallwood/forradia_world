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
    * @class Tile
    * @brief Represents a tile in the game world.
    *
    * A tile is a fundamental building block of the game world. It can hold information
    * about the ground type, an object placed on the tile, and a creature occupying it.
    */
    class Tile
    {
      public:
        /**
        * @brief Gets the ground type of the tile.
        * @return The hashed value representing the ground type.
        */
        auto GetGround() const
        {
            return m_ground;
        }

        /**
        * @brief Sets the ground type for the tile.
        * @param groundName The name of the ground type to be set.
        * @note The name will be hashed before being stored.
        */
        void SetGround(std::string_view groundName)
        {
            m_ground = Hash(groundName);
        }

        /**
        * @brief Gets the object placed on the tile.
        * @return The hashed value representing the object.
        */
        auto GetObject() const
        {
            return m_object;
        }

        /**
        * @brief Sets the object to be placed on the tile.
        * @param objectName The name of the object to be set.
        * @note The name will be hashed before being stored.
        */
        void SetObject(std::string_view objectName)
        {
            m_object = Hash(objectName);
        }

        /**
        * @brief Gets the creature currently occupying the tile.
        * @return A shared pointer to the creature occupying the tile.
        */
        auto GetCreature() const
        {
            return m_creature;
        }

        /**
        * @brief Sets the creature occupying the tile.
        * @param value A shared pointer to the creature to be set.
        */
        void SetCreature(std::shared_ptr<Creature> value)
        {
            m_creature = value;
        }

      private:
        int m_ground { 0 }; /**< The hashed value representing the ground type. */
        int m_object { 0 }; /**< The hashed value representing the object on the tile. */
        std::shared_ptr<Creature> m_creature; /**< A shared pointer to the creature occupying the tile. */
    };
}
