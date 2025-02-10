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
    * @brief Gets the size of the grid (number of columns and rows).
    *
    * This function calculates the grid size based on the aspect ratio and the number of grid rows.
    * It returns the number of columns and rows as a `Size` object.
    *
    * @return Size The size of the grid, with columns as the first value and rows as the second.
    */
    Size GetGridSize();

    /**
    * @brief Gets the size of a single tile (width and height).
    *
    * This function calculates the tile size based on the grid settings. It computes the height from the
    * number of grid rows and derives the corresponding width using the aspect ratio.
    *
    * @return SizeF The size of a tile, with width as the first value and height as the second.
    */
    SizeF GetTileSize();
}
