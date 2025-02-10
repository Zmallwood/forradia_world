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

#include "Tile.hpp"

#include "Theme1.Core.Devices/SettingsDevice.hpp"

namespace ForradiaWorld
{
    WorldArea::WorldArea()
    {
        auto size = _<SettingsDevice>().k_worldAreaSize;

        for (auto x = 0; x < size.w; x++)
        {
            m_tiles.push_back(std::vector<std::shared_ptr<Tile>>());

            for (auto y = 0; y < size.h; y++)
            {
                m_tiles.at(x).push_back(std::make_shared<Tile>());
            }
        }
    }

    std::shared_ptr<Tile> WorldArea::GetTile(int x, int y) const
    {
        return m_tiles.at(x).at(y);
    }

    std::shared_ptr<Tile> WorldArea::GetTile(Point coordinate) const
    {
        return GetTile(coordinate.x, coordinate.y);
    }

    Size WorldArea::GetSize() const
    {
        auto width = static_cast<int>(m_tiles.size());
        auto height = 0;

        if (width)
        {
            height = static_cast<int>(m_tiles.at(0).size());
        }

        return { width, height };
    }

    bool WorldArea::IsValidCoordinate(int x, int y) const
    {
        auto size = GetSize();

        return x >= 0 && y >= 0 && x < size.w && y < size.h;
    }
}
