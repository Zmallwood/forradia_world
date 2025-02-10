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
    class WorldArea;

    /**
    * @class World
    * @brief Represents the game world, holding information about the current world area.
    *
    * This class manages the game world and provides access to the current world area.
    * It is responsible for storing and retrieving the active world area at any given time.
    */
    class World
    {
      public:
        /**
        * @brief Constructs a new World object.
        *
        * The constructor initializes the world by setting the current world area.
        */
        World();

        /**
        * @brief Gets the current world area.
        * @return A shared pointer to the current world area.
        */
        auto GetCurrentWorldArea() const
        {
            return m_currentWorldArea;
        }

      private:
        std::shared_ptr<WorldArea> m_currentWorldArea; /**< A shared pointer to the current world area. */
    };
}
