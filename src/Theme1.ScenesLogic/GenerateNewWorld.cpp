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
        // Retrieve current world area and references for creatures
        auto worldArea = _<World>().GetCurrentWorldArea();
        auto& creaturesMirrorRef = worldArea->GetCreaturesMirrorRef();
        auto size = worldArea->GetSize();

        // Helper function to set ground for all tiles in the world
        auto SetGroundForArea = [&](const std::string& groundType)
        {
            for (auto y = 0; y < size.h; y++) // Loop over the height of the world
            {
                for (auto x = 0; x < size.w; x++) // Loop over the width of the world
                {
                    auto tile = worldArea->GetTile(x, y); // Get the tile at coordinates (x, y)
                    tile->SetGround(groundType); // Set the ground type (e.g., grass or water)
                }
            }
        };

        // Initialize the ground with grass for all tiles
        SetGroundForArea("GroundGrass");

        // Helper function to generate lakes at random locations in the world
        auto GenerateLakes = [&](int numLakes)
        {
            for (auto i = 0; i < numLakes; i++) // Generate a specified number of lakes
            {
                auto xCenter = rand() % size.w; // Random X coordinate for lake center
                auto yCenter = rand() % size.h; // Random Y coordinate for lake center
                auto r = 3 + rand() % 8; // Random radius for lake (between 3 and 10)

                // Loop over the area around the lake center
                for (auto y = yCenter - r; y <= yCenter + r; y++)
                {
                    for (auto x = xCenter - r; x <= xCenter + r; x++)
                    {
                        if (!worldArea->IsValidCoordinate(x, y)) // Skip invalid coordinates
                        {
                            continue;
                        }

                        auto dx = x - xCenter; // Distance in X direction from center
                        auto dy = y - yCenter; // Distance in Y direction from center

                        // Check if the point lies within the lake radius
                        if (dx * dx + dy * dy <= r * r)
                        {
                            auto tile = worldArea->GetTile(x, y); // Get the tile at the current coordinates
                            tile->SetGround("GroundWater"); // Set the ground type to water
                        }
                    }
                }
            }
        };

        // Generate a random number of lakes (between 30 and 40)
        GenerateLakes(30 + rand() % 10);

        // Helper function to generate objects (e.g., trees, flowers) at random locations
        auto GenerateObjectAtRandomCoordinates = [&](const std::string& objectType, int numObjects)
        {
            for (auto i = 0; i < numObjects; i++) // Generate the specified number of objects
            {
                auto x = rand() % size.w; // Random X coordinate
                auto y = rand() % size.h; // Random Y coordinate

                auto tile = worldArea->GetTile(x, y); // Get the tile at the random coordinates
                if (tile->GetGround() != Hash("GroundWater")) // Ensure the object is not placed on water
                {
                    tile->SetObject(objectType); // Place the object (e.g., tree, flower)
                }
            }
        };

        // Generate trees, flowers, and boulders at random locations
        GenerateObjectAtRandomCoordinates("ObjectTree1", 800); // Generate 200 Tree1 objects
        GenerateObjectAtRandomCoordinates("ObjectTree2", 800); // Generate 200 Tree2 objects
        GenerateObjectAtRandomCoordinates("ObjectPinkFlower", 200); // Generate 200 PinkFlower objects
        GenerateObjectAtRandomCoordinates("ObjectStoneBoulder", 200); // Generate 200 StoneBoulder objects

        // Helper function to generate creatures (e.g., rabbits, enemies) at random locations
        auto GenerateCreatures = [&](const std::string& creatureType, int numCreatures)
        {
            for (auto i = 0; i < numCreatures; i++) // Generate the specified number of creatures
            {
                auto x = rand() % size.w; // Random X coordinate
                auto y = rand() % size.h; // Random Y coordinate

                auto tile = worldArea->GetTile(x, y); // Get the tile at the random coordinates

                if (tile->GetGround() != Hash("GroundWater")) // Ensure the creature is not placed on water
                {
                    std::shared_ptr<Creature> newCreature;

                    // Create a new creature based on the specified type
                    if (creatureType == "AnimalWhiteRabbit")
                        newCreature = std::make_shared<Animal>(creatureType);
                    else if (creatureType == "Enemy1")
                        newCreature = std::make_shared<Enemy>(creatureType);

                    tile->SetCreature(newCreature); // Place the creature on the tile
                    creaturesMirrorRef.insert({ newCreature, { x, y } }); // Update the creature reference
                }
            }
        };

        // Generate white rabbits and enemies at random locations
        GenerateCreatures("AnimalWhiteRabbit", 200); // Generate 200 white rabbit creatures
        GenerateCreatures("Enemy1", 200); // Generate 200 enemy creatures

        // Define starting coordinates and size for the fenced area
        auto startCoordinate = Point { 50, 50 }; // Start coordinate for the player
        auto areaSize = Size { 11, 11 }; // Size of the fenced area (11x11)

        // Calculate the bounds for the fence (left, right, top, bottom)
        auto left = startCoordinate.x - (areaSize.w - 1) / 2;
        auto right = startCoordinate.x + (areaSize.w - 1) / 2;
        auto top = startCoordinate.y - (areaSize.h - 1) / 2;
        auto bottom = startCoordinate.y + (areaSize.h - 1) / 2;

        auto startTile = worldArea->GetTile(startCoordinate); // Get the starting tile

        // Set the ground and objects for the fenced area
        for (auto y = top; y < bottom; y++) // Loop over the vertical range of the fenced area
        {
            for (auto x = left; x < right; x++) // Loop over the horizontal range of the fenced area
            {
                auto tile = worldArea->GetTile(x, y); // Get the tile at the current coordinates
                tile->SetGround("GroundGrass"); // Set the ground type to grass

                // Set vertical fence pieces along the left and right edges
                if (x == left || x == right - 1)
                {
                    tile->SetObject("ObjectWoodenFenceVertical");
                }

                // Set horizontal fence pieces along the top and bottom edges
                if (y == top || y == bottom - 1)
                {
                    tile->SetObject("ObjectWoodenFenceHorizontal");
                }

                // Set corner fence pieces
                if (x == left && y == top)
                {
                    tile->SetObject("ObjectWoodenFenceNW");
                }

                if (x == right - 1 && y == top)
                {
                    tile->SetObject("ObjectWoodenFenceNE");
                }

                if (x == left && y == bottom - 1)
                {
                    tile->SetObject("ObjectWoodenFenceSW");
                }

                if (x == right - 1 && y == bottom - 1)
                {
                    tile->SetObject("ObjectWoodenFenceSE");
                }
            }
        }

        // Set the claim flag at the starting position of the player
        startTile->SetObject("ObjectClaimFlag");
    }
}
