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

#include "WorldArea.hpp"
#include "Theme1.Core.Devices/SettingsDevice.hpp"
#include "Tile.hpp"

namespace ForradiaWorld
{
    WorldArea::WorldArea()
    {
        // Get the world area size from the settings device
        auto size = _<SettingsDevice>().k_worldAreaSize;

        // Initialize the 2D vector to store tiles for each row
        for (auto x = 0; x < size.w; x++)
        {
            m_tiles.push_back(std::vector<std::shared_ptr<Tile>>());

            // Initialize each column (tile) in the row
            for (auto y = 0; y < size.h; y++)
            {
                m_tiles.at(x).push_back(std::make_shared<Tile>());
            }
        }
    }

    std::shared_ptr<Tile> WorldArea::GetTile(int x, int y) const
    {
        // Return the tile at the specified (x, y) coordinates
        return m_tiles.at(x).at(y);
    }

    std::shared_ptr<Tile> WorldArea::GetTile(Point coordinate) const
    {
        // Return the tile using the coordinate object
        return GetTile(coordinate.x, coordinate.y);
    }

    Size WorldArea::GetSize() const
    {
        // Get the width (number of rows) and height (number of columns) of the world area
        auto width = static_cast<int>(m_tiles.size());
        auto height = 0;

        // If the world area is not empty, set the height from the first row
        if (width)
        {
            height = static_cast<int>(m_tiles.at(0).size());
        }

        // Return the size as a Size object
        return { width, height };
    }

    bool WorldArea::IsValidCoordinate(int x, int y) const
    {
        // Get the size of the world area
        auto size = GetSize();

        // Check if the coordinates are within the bounds of the world area
        return x >= 0 && y >= 0 && x < size.w && y < size.h;
    }

}
