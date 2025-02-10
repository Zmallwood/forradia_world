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

#include "TileHoveringService.hpp"
#include "Theme1.Core.Devices/HeroDevice.hpp"
#include "TileGridMath.hpp"

namespace ForradiaWorld
{
    void TileHoveringService::Update()
    {
        // Get the current mouse position on the screen
        auto mousePosition = GetMousePosition();

        // Get the size of the grid (number of columns and rows)
        auto gridSize = GetGridSize();

        // Get the size of each tile in the grid
        auto tileSize = GetTileSize();

        // Get the current position of the hero in the world
        auto heroPos = _<HeroDevice>().GetPosition();

        // Calculate the relative position of the mouse within the tile grid (in terms of grid coordinates)
        auto relX = mousePosition.x / tileSize.w;
        auto relY = mousePosition.y / tileSize.h;

        // Calculate the grid coordinates for the hovered tile based on the hero's position
        auto xCoord = static_cast<int>(heroPos.x - (gridSize.w - 1) / 2 + relX);
        auto yCoord = static_cast<int>(heroPos.y - (gridSize.h - 1) / 2 + relY);

        // Store the coordinates of the currently hovered tile
        m_hoveredTile = { xCoord, yCoord };
    }
}
