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

#include "UpdateAnimalsMovement.hpp"
#include "Theme1.Core.World/Animal.hpp"
#include "Theme1.Core.World/Tile.hpp"
#include "Theme1.Core.World/World.hpp"
#include "Theme1.Core.World/WorldArea.hpp"

namespace ForradiaWorld
{
    void UpdateAnimalsMovement()
    {
        // Retrieve the current world area
        auto worldArea = _<World>().GetCurrentWorldArea();

        // Get a reference to the creatures' mirror, which holds creature positions
        auto& creaturesMirrorRef = worldArea->GetCreaturesMirrorRef();

        // Get the current time in milliseconds
        auto now = SDL_GetTicks();

        // Iterate through all creatures in the mirror reference
        for (auto it = creaturesMirrorRef.begin(); it != creaturesMirrorRef.end();)
        {
            // Get the current creature and its position
            auto creature = it->first;
            Point coord = it->second;

            // Check if the creature is an animal
            auto animal = std::dynamic_pointer_cast<Animal>(creature);

            // If the creature is an animal, we proceed to check for movement
            if (animal)
            {
                // Check if enough time has passed based on the animal's movement speed
                if (now > animal->GetTicksLastMovement() + 1000 / animal->GetMovementSpeed())
                {
                    // Randomly determine a direction for the animal to move
                    auto dx = rand() % 2 - rand() % 2; // Movement in the x direction (-1, 0, or 1)
                    auto dy = rand() % 2 - rand() % 2; // Movement in the y direction (-1, 0, or 1)

                    // Calculate the new coordinates after moving
                    auto newX = coord.x + dx;
                    auto newY = coord.y + dy;

                    // Ensure the new position is within bounds and there is actual movement
                    if (newX >= 0 && newY >= 0 && newX < 100 && newY < 100 && (dx || dy))
                    {
                        // Get the old and new tiles based on coordinates
                        auto oldTile = worldArea->GetTile(coord.x, coord.y);
                        auto newTile = worldArea->GetTile(newX, newY);

                        // Check if the new tile is empty (no creature or object)
                        if (!newTile->GetCreature() && !newTile->GetObject())
                        {
                            // Move the creature to the new tile, clear the old tile
                            newTile->SetCreature(animal);
                            oldTile->SetCreature(nullptr);

                            // Update the creatures' mirror with the new position
                            creaturesMirrorRef.erase(it);
                            creaturesMirrorRef.insert({ animal, { newX, newY } });

                            // Update the animal's last movement time
                            animal->SetTicksLastMovement(now);

                            // Move to the next creature in the list
                            ++it;

                            // Skip the rest of the loop and continue to the next creature
                            continue;
                        }
                    }
                }
            }

            // Move to the next creature if no movement took place
            ++it;
        }
    }
}
