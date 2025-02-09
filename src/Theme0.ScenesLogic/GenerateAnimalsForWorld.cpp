// Copyright 2025 Andreas Åkerberg

#include "GenerateAnimalsForWorld.hpp"
#include "Theme0.Core.World/Animal.hpp"
#include "Theme0.Core.World/Tile.hpp"
#include "Theme0.Core.World/World.hpp"
#include "Theme0.Core.World/WorldArea.hpp"

namespace ForradiaWorld
{
    void GenerateAnimalsForWorld()
    {
        auto worldArea = _<World>().GetCurrentWorldArea();
        auto& creaturesMirrorRef = worldArea->GetCreaturesMirrorRef();

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
