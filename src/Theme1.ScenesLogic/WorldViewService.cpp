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
        auto worldArea = _<World>().GetCurrentWorldArea();
        Point heroPos = _<HeroDevice>().GetPosition();

        Size gridSize = GetGridSize();
        SizeF tileSize = GetTileSize();

        Point hoveredTile = _<TileHoveringService>().GetHoveredTile();

        float smallValue = 0.002f;

        for (auto y = 0; y < gridSize.h; y++)
        {
            for (auto x = 0; x < gridSize.w; x++)
            {
                int coordX = heroPos.x - (gridSize.w - 1) / 2 + x;
                int coordY = heroPos.y - (gridSize.h - 1) / 2 + y;

                if (!worldArea->IsValidCoordinate(coordX, coordY))
                {
                    continue;
                }

                auto tile = worldArea->GetTile(coordX, coordY);

                RectF dest { x * tileSize.w, y * tileSize.h, tileSize.w + smallValue, tileSize.h + smallValue };

                auto sightBlocked { false };

                auto dx = heroPos.x - coordX;
                auto dy = heroPos.y - coordY;

                auto numSteps = std::max(std::abs(dx), std::abs(dy));

                auto stepX = static_cast<float>(dx) / numSteps;
                auto stepY = static_cast<float>(dy) / numSteps;

                auto currX = static_cast<float>(coordX);
                auto currY = static_cast<float>(coordY);

                for (auto i = 0; i < numSteps - 1; i++)
                {
                    currX += stepX;
                    currY += stepY;

                    auto stepCoordX = static_cast<int>(currX);
                    auto stepCoordY = static_cast<int>(currY);

                    auto currTile = worldArea->GetTile(stepCoordX, stepCoordY);

                    auto object = currTile->GetObject();

                    if (object)
                    {
                        if (_<ObjectIndexDevice>().ObjectAllowsSight(object))
                        {
                            continue;
                        }

                        sightBlocked = true;

                        break;
                    }
                }

                if (sightBlocked)
                {
                    continue;
                }

                int ground = tile->GetGround();

                if (ground == Hash("GroundWater"))
                {
                    int animIndex = ((SDL_GetTicks() + 10 * coordX * coordY) % 1200) / 400;

                    std::string animName = "GroundWater_" + std::to_string(animIndex);

                    ground = Hash(animName);
                }

                _<ImageDrawDevice>().DrawImage(ground, dest);

                if (coordX == hoveredTile.x && coordY == hoveredTile.y)
                {
                    _<ImageDrawDevice>().DrawImage("HoveredTile", dest);
                }

                int object = tile->GetObject();

                _<ImageDrawDevice>().DrawImage(object, dest);

                auto creature = tile->GetCreature();

                if (creature)
                {
                    _<ImageDrawDevice>().DrawImage(creature->GetType(), dest);
                }

                if (coordX == heroPos.x && coordY == heroPos.y)
                {
                    _<ImageDrawDevice>().DrawImage("Player", dest);
                }
            }
        }
    }
}
