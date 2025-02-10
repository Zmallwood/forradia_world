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

#include "WorldViewService.hpp"
#include "Theme1.Core.Devices/HeroDevice.hpp"
#include "Theme1.Core.Devices/ImageDrawDevice.hpp"
#include "Theme1.Core.Devices/ObjectIndexDevice.hpp"
#include "Theme1.Core.World/Everything.hpp"
#include "Theme1.ScenesLogic/TileGridMath.hpp"
#include "TileHoveringService.hpp"

namespace ForradiaWorld
{
    void WorldViewService::Render() const
    {
        // Get the current world area and hero's position
        auto worldArea = _<World>().GetCurrentWorldArea();
        Point heroPos = _<HeroDevice>().GetPosition();

        // Get grid size and tile size for rendering
        Size gridSize = GetGridSize();
        SizeF tileSize = GetTileSize();

        // Get the currently hovered tile position
        Point hoveredTile = _<TileHoveringService>().GetHoveredTile();

        // Small value for tile rendering adjustments
        float smallValue = 0.002f;

        // Iterate through all tiles in the grid
        for (auto y = 0; y < gridSize.h; y++)
        {
            for (auto x = 0; x < gridSize.w; x++)
            {
                // Calculate the tile's coordinates
                int coordX = heroPos.x - (gridSize.w - 1) / 2 + x;
                int coordY = heroPos.y - (gridSize.h - 1) / 2 + y;

                // Skip invalid coordinates that are outside the world area
                if (!worldArea->IsValidCoordinate(coordX, coordY))
                {
                    continue;
                }

                // Get the tile at the current coordinates
                auto tile = worldArea->GetTile(coordX, coordY);

                // Define the destination rectangle for the tile
                RectF dest { x * tileSize.w, y * tileSize.h, tileSize.w + smallValue, tileSize.h + smallValue };

                // Flag to check if the line of sight is blocked
                auto sightBlocked { false };

                // Calculate the direction of movement towards the hero
                auto dx = heroPos.x - coordX;
                auto dy = heroPos.y - coordY;

                // Calculate the number of steps required for line of sight check
                auto numSteps = std::max(std::abs(dx), std::abs(dy));

                // Step size for each step in the x and y direction
                auto stepX = static_cast<float>(dx) / numSteps;
                auto stepY = static_cast<float>(dy) / numSteps;

                // Current position along the path
                auto currX = static_cast<float>(coordX);
                auto currY = static_cast<float>(coordY);

                // Iterate through each step in the line of sight to check if it’s blocked
                for (auto i = 0; i < numSteps - 1; i++)
                {
                    currX += stepX;
                    currY += stepY;

                    // Convert current floating-point position to integer coordinates
                    auto stepCoordX = static_cast<int>(currX);
                    auto stepCoordY = static_cast<int>(currY);

                    // Get the tile at the step position
                    auto currTile = worldArea->GetTile(stepCoordX, stepCoordY);

                    // Check if there’s an object blocking the line of sight
                    auto object = currTile->GetObject();

                    if (object)
                    {
                        // If object blocks sight, mark sight as blocked and stop checking
                        if (_<ObjectIndexDevice>().ObjectAllowsSight(object))
                        {
                            continue;
                        }

                        sightBlocked = true;

                        break;
                    }
                }

                // Skip tile if sight is blocked
                if (sightBlocked)
                {
                    continue;
                }

                // Get the ground type of the current tile
                int ground = tile->GetGround();

                // Special handling for "GroundWater" to add animation
                if (ground == Hash("GroundWater"))
                {
                    int animIndex = ((SDL_GetTicks() + 10 * coordX * coordY) % 1200) / 400;

                    std::string animName = "GroundWater_" + std::to_string(animIndex);

                    ground = Hash(animName);
                }

                // Draw the ground of the current tile
                _<ImageDrawDevice>().DrawImage(ground, dest);

                // If the current tile is hovered, draw the hovered tile image
                if (coordX == hoveredTile.x && coordY == hoveredTile.y)
                {
                    _<ImageDrawDevice>().DrawImage("HoveredTile", dest);
                }

                // Get the object on the current tile, if it exists, and draw it
                int object = tile->GetObject();

                if (object)
                {
                    _<ImageDrawDevice>().DrawImage(object, dest);
                }

                // If there is a creature on the tile, draw it
                auto creature = tile->GetCreature();

                if (creature)
                {
                    _<ImageDrawDevice>().DrawImage(creature->GetType(), dest);
                }

                // If the current tile is the hero's position, draw the player
                if (coordX == heroPos.x && coordY == heroPos.y)
                {
                    _<ImageDrawDevice>().DrawImage("Player", dest);
                }
            }
        }
    }
}
