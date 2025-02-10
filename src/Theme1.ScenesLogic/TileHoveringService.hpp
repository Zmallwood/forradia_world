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
    * @class TileHoveringService
    * @brief Service responsible for tracking the hovered tile on the grid.
    *
    * This class handles tracking the hovered tile based on the mouse position and the hero's position on the grid.
    */
    class TileHoveringService
    {
      public:
        /**
        * @brief Updates the tracking of the hovered tile based on the mouse position and the hero's position.
        *
        * This method calculates which tile is currently being hovered by the mouse and updates the `m_hoveredTile`
        * variable with the corresponding grid coordinates. It takes into account the hero's position and the size of
        * the grid and tiles.
        */
        void Update();

        /**
        * @brief Gets the current hovered tile's coordinates.
        *
        * @return The coordinates of the currently hovered tile as a `Point` structure.
        */
        auto GetHoveredTile() const
        {
            return m_hoveredTile;
        }

      private:
        /**
        * @brief The coordinates of the currently hovered tile.
        *
        * This variable stores the grid coordinates of the tile that is currently being hovered by the mouse.
        * Initially set to (-1, -1) to represent an invalid or uninitialized state.
        */
        Point m_hoveredTile { -1, -1 };
    };
}
