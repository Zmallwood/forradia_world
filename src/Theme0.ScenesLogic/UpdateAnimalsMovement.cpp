// Copyright 2025 Andreas Åkerberg

#include "UpdateAnimalsMovement.hpp"

#include "Theme0.Core.World/Animal.hpp"

#include "Theme0.Core.World/Tile.hpp"

#include "Theme0.Core.World/World.hpp"

#include "Theme0.Core.World/WorldArea.hpp"

namespace ForradiaWorld
{

    void UpdateAnimalsMovement()
    {
        auto worldArea = _<World>().GetCurrentWorldArea();

        auto& creaturesMirrorRef = worldArea->GetCreaturesMirrorRef();

        auto now = SDL_GetTicks();

        for (auto it = creaturesMirrorRef.begin(); it != creaturesMirrorRef.end();)
        {
            auto creature = it->first;
            Point coord = it->second;

            auto animal = std::dynamic_pointer_cast<Animal>(creature);

            if (animal)
            {
                if (now > animal->GetTicksLastMovement() + 1000 / animal->GetMovementSpeed())
                {
                    auto dx = rand() % 2 - rand() % 2;
                    auto dy = rand() % 2 - rand() % 2;

                    auto newX = coord.x + dx;
                    auto newY = coord.y + dy;

                    if (newX >= 0 && newY >= 0 && newX < 100 && newY < 100 && (dx || dy))
                    {
                        auto oldTile = worldArea->GetTile(coord.x, coord.y);
                        auto newTile = worldArea->GetTile(newX, newY);

                        if (!newTile->GetCreature() && !newTile->GetObject())
                        {
                            newTile->SetCreature(animal);
                            oldTile->SetCreature(nullptr);

                            creaturesMirrorRef.erase(it);
                            creaturesMirrorRef.insert({ animal, { newX, newY } });

                            animal->SetTicksLastMovement(now);

                            ++it;

                            continue;
                        }
                    }
                }
            }

            ++it;
        }
    }

}
