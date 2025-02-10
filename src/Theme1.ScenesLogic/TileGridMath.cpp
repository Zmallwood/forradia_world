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
        // Retrieve the number of rows in the grid from settings
        auto numGridRows = _<SettingsDevice>().k_numGridRows;

        // Get the aspect ratio for the grid
        auto aspectRatio = GetAspectRatio();

        // Calculate the number of columns based on the rows and aspect ratio
        auto numGridCols = static_cast<int>(numGridRows * aspectRatio) + 1;

        // Return the grid size as a Size structure (columns, rows)
        return { numGridCols, numGridRows };
    }

    SizeF GetTileSize()
    {
        // Retrieve the number of rows in the grid from settings
        auto numGridRows = _<SettingsDevice>().k_numGridRows;

        // Calculate the tile height based on the number of grid rows
        auto tileHeight = 1.0f / numGridRows;

        // Convert the tile height to its corresponding width based on the aspect ratio
        auto tileWidth = ConvertHeightToWidth(tileHeight);

        // Return the tile size as a SizeF structure (width, height)
        return { tileWidth, tileHeight };
    }
}
