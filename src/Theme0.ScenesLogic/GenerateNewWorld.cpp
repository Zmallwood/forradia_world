// Copyright 2025 Andreas Åkerberg

#include "GenerateNewWorld.hpp"
#include "Theme0.Core.World/Everything.hpp"

namespace ForradiaWorld
{
    void GenerateNewWorld()
    {
#define ___SETUP___

        auto worldArea = _<World>().GetCurrentWorldArea();

        auto& creaturesMirrorRef = worldArea->GetCreaturesMirrorRef();

#define ___CLEARWORLD_WITH_GRASS___

        for (auto y = 0; y < 100; y++)
        {
            for (auto x = 0; x < 100; x++)
            {
                auto tile = worldArea->GetTile(x, y);

                tile->SetGround("GroundGrass");
            }
        }

#define ___GENERATE_WATER___

        auto numLakes = 30 + rand() % 10;

        for (auto i = 0; i < numLakes; i++)
        {
            auto xCenter = rand() % 100;
            auto yCenter = rand() % 100;

            auto r = 3 + rand() % 8;

            for (auto y = yCenter - r; y <= yCenter + r; y++)
            {
                for (auto x = xCenter - r; x <= xCenter + r; x++)
                {
                    if (x < 0 || y < 0 || x >= 100 || y >= 100)
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
            auto x = rand() % 100;
            auto y = rand() % 100;

            auto tile = worldArea->GetTile(x, y);

            if (tile->GetGround() != Hash("GroundWater"))
            {
                tile->SetObject("ObjectTree1");
            }
        }

        auto numTree2s = 200;

        for (auto i = 0; i < numTree2s; i++)
        {
            auto x = rand() % 100;
            auto y = rand() % 100;

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
            auto x = rand() % 100;
            auto y = rand() % 100;

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
