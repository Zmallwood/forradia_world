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

#include "GenerateNewWorld.hpp"

#include "Theme1.Core.World/Everything.hpp"

namespace ForradiaWorld
{
    void GenerateNewWorld()
    {
#define ___SETUP___

        auto worldArea = _<World>().GetCurrentWorldArea();

        auto& creaturesMirrorRef = worldArea->GetCreaturesMirrorRef();

        auto size = worldArea->GetSize();

#define ___CLEARWORLD_WITH_GRASS___

        for (auto y = 0; y < size.h; y++)
        {
            for (auto x = 0; x < size.w; x++)
            {
                auto tile = worldArea->GetTile(x, y);

                tile->SetGround("GroundGrass");
            }
        }

#define ___GENERATE_WATER___

        auto numLakes = 30 + rand() % 10;

        for (auto i = 0; i < numLakes; i++)
        {
            auto xCenter = rand() % size.w;
            auto yCenter = rand() % size.h;

            auto r = 3 + rand() % 8;

            for (auto y = yCenter - r; y <= yCenter + r; y++)
            {
                for (auto x = xCenter - r; x <= xCenter + r; x++)
                {
                    if (!worldArea->IsValidCoordinate(x, y))
                    {
                        continue;
                    }

                    auto dx = x - xCenter;
                    auto dy = y - yCenter;

                    if (dx * dx + dy * dy <= r * r)
                    {
                        auto tile = worldArea->GetTile(x, y);

                        tile->SetGround("GroundWater");
                    }
                }
            }
        }

#define ___GENERATE_OBJECTS___

        auto numTree1s = 200;

        for (auto i = 0; i < numTree1s; i++)
        {
            auto x = rand() % size.w;
            auto y = rand() % size.h;

            auto tile = worldArea->GetTile(x, y);

            if (tile->GetGround() != Hash("GroundWater"))
            {
                tile->SetObject("ObjectTree1");
            }
        }

        auto numTree2s = 200;

        for (auto i = 0; i < numTree2s; i++)
        {
            auto x = rand() % size.w;
            auto y = rand() % size.h;

            auto tile = worldArea->GetTile(x, y);

            if (tile->GetGround() != Hash("GroundWater"))
            {
                tile->SetObject("ObjectTree2");
            }
        }

        auto startTile = worldArea->GetTile(50, 50);

        startTile->SetObject("ObjectClaimFlag");

#define ___GENERATE_ANIMALS___

        auto numWhiteRabbits = 200;

        for (auto i = 0; i < numWhiteRabbits; i++)
        {
            auto x = rand() % size.w;
            auto y = rand() % size.h;

            auto tile = worldArea->GetTile(x, y);

            if (tile->GetGround() != Hash("GroundWater"))
            {
                auto newCreature = std::make_shared<Animal>("AnimalWhiteRabbit");

                tile->SetCreature(newCreature);

                creaturesMirrorRef.insert({ newCreature, { x, y } });
            }
        }
    }
}
