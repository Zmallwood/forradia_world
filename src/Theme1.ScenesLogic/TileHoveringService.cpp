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
        auto mousePosition = GetMousePosition();
        auto gridSize = GetGridSize();
        auto tileSize = GetTileSize();
        auto heroPos = _<HeroDevice>().GetPosition();

        auto relX = mousePosition.x / tileSize.w;
        auto relY = mousePosition.y / tileSize.h;

        auto xCoord = static_cast<int>(heroPos.x - (gridSize.w - 1) / 2 + relX);
        auto yCoord = static_cast<int>(heroPos.y - (gridSize.h - 1) / 2 + relY);

        m_hoveredTile = { xCoord, yCoord };
    }
}
