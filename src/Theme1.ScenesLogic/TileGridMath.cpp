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

#include "TileGridMath.hpp"
#include "Theme1.Core.Devices/SettingsDevice.hpp"

namespace ForradiaWorld
{
    Size GetGridSize()
    {
        auto numGridRows = _<SettingsDevice>().k_numGridRows;

        auto aspectRatio = GetAspectRatio();

        auto numGridCols = static_cast<int>(numGridRows * aspectRatio) + 1;

        return { numGridCols, numGridRows };
    }

    SizeF GetTileSize()
    {
        auto numGridRows = _<SettingsDevice>().k_numGridRows;

        auto tileHeight = 1.0f / numGridRows;

        auto tileWidth = ConvertHeightToWidth(tileHeight);

        return { tileWidth, tileHeight };
    }
}
