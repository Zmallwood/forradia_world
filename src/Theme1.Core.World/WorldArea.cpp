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

namespace ForradiaWorld
{

    WorldArea::WorldArea()
    {
        for (auto x = 0; x < 100; x++)
        {
            m_tiles.push_back(std::vector<std::shared_ptr<Tile>>());

            for (auto y = 0; y < 100; y++)
            {
                m_tiles.at(x).push_back(std::make_shared<Tile>());
            }
        }
    }

    std::shared_ptr<Tile> WorldArea::GetTile(int x, int y) const
    {
        return m_tiles.at(x).at(y);
    }

}
