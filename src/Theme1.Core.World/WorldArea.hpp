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
    class Tile;
    class Creature;

    /**
    * @class WorldArea
    * @brief Class representing a world area containing tiles and creatures.
    *
    * This class manages a 2D grid of tiles, allowing access to individual tiles, checking if coordinates are valid,
    * and maintaining a mirror reference of creatures and their positions.
    */
    class WorldArea
    {
      public:
        /**
        * @brief Constructor that initializes the world area with tiles.
        *
        * This constructor creates a 2D grid of tiles based on the size defined in the settings.
        */
        WorldArea();

        /**
        * @brief Gets a tile at the specified (x, y) coordinates.
        *
        * @param x The x-coordinate of the tile.
        * @param y The y-coordinate of the tile.
        *
        * @return A shared pointer to the Tile at the specified coordinates.
        */
        std::shared_ptr<Tile> GetTile(int x, int y) const;

        /**
        * @brief Gets a tile at the specified coordinate.
        *
        * @param coordinate A Point object containing the x and y coordinates of the tile.
        *
        * @return A shared pointer to the Tile at the specified coordinate.
        */
        std::shared_ptr<Tile> GetTile(Point coordinate) const;

        /**
        * @brief Gets the size of the world area.
        *
        * @return The width and height of the world area as a Size object.
        */
        Size GetSize() const;

        /**
        * @brief Checks if the given coordinates are valid within the world area.
        *
        * @param x The x-coordinate to check.
        * @param y The y-coordinate to check.
        *
        * @return True if the coordinates are within the bounds of the world area, otherwise false.
        */
        bool IsValidCoordinate(int x, int y) const;

        /**
        * @brief Gets a reference to the creatures mirror.
        *
        * The creatures mirror is a map that associates creatures with their respective positions.
        *
        * @return A reference to the map of creatures and their positions.
        */
        auto& GetCreaturesMirrorRef()
        {
            return m_creaturesMirror;
        }

      private:
        /// A 2D vector storing shared pointers to tiles in the world area.
        std::vector<std::vector<std::shared_ptr<Tile>>> m_tiles;

        /// A map storing creatures and their respective positions in the world area.
        std::map<std::shared_ptr<Creature>, Point> m_creaturesMirror;
    };

}
