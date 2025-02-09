// Copyright 2025 Andreas Åkerberg

#include "WorldView.hpp"

#include "Theme0.Core.Devices/HeroDevice.hpp"

#include "Theme0.Core.Devices/ImageDrawDevice.hpp"

#include "Theme0.Core.World/Everything.hpp"

#include "Theme0.ScenesLogic/TileGridMath.hpp"

#include "TileHovering.hpp"

namespace ForradiaWorld
{

    void WorldView::Render() const
    {
        /*\
=================== SETUP ====================*/

        auto worldArea = _<World>().GetCurrentWorldArea();
        Point heroPos = _<HeroDevice>().GetPosition();

        Size gridSize = GetGridSize();
        SizeF tileSize = GetTileSize();

        Point hoveredTile = _<TileHovering>().GetHoveredTile();

        float smallValue = 0.003f;

        /*\
=================== TILE GRID LOOP ====================*/

        for (auto y = 0; y < gridSize.h; y++)
        {
            for (auto x = 0; x < gridSize.w; x++)
            {

                /*\
=================== TILE SETUP ====================*/

                int coordX = heroPos.x - (gridSize.w - 1) / 2 + x;
                int coordY = heroPos.y - (gridSize.h - 1) / 2 + y;

                if (coordX < 0 || coordY < 0 || coordX >= 100 || coordY >= 100)
                {
                    continue;
                }

                auto tile = worldArea->GetTile(coordX, coordY);

                RectF dest { x * tileSize.w, y * tileSize.h, tileSize.w + smallValue, tileSize.h + smallValue };

                /*\
*=================== BLOCKED SIGHT ====================*/

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

                    if (currTile->GetObject())
                    {
                        sightBlocked = true;

                        break;
                    }
                }

                if (sightBlocked)
                {
                    continue;
                }

                /*\
*=================== GROUND RENDERING ====================*/

                int ground = tile->GetGround();

                if (ground == Hash("GroundWater"))
                {
                    int animIndex = (SDL_GetTicks() % 1200) / 400;

                    std::string animName = "GroundWater_" + std::to_string(animIndex);

                    ground = Hash(animName);
                }

                /*\
*=================== OBJECTS RENDERING ====================*/

                _<ImageDrawDevice>().DrawImage(ground, dest);

                if (coordX == hoveredTile.x && coordY == hoveredTile.y)
                {
                    _<ImageDrawDevice>().DrawImage("HoveredTile", dest);
                }

                int object = tile->GetObject();

                _<ImageDrawDevice>().DrawImage(object, dest);

                /*\
*=================== CREATURE RENDERING ====================*/

                auto creature = tile->GetCreature();

                if (creature)
                {
                    _<ImageDrawDevice>().DrawImage(creature->GetType(), dest);
                }

                /*\
*=================== PLAYER RENDERING ====================*/

                if (coordX == heroPos.x && coordY == heroPos.y)
                {
                    _<ImageDrawDevice>().DrawImage("Player", dest);
                }
            }
        }
    }

}
