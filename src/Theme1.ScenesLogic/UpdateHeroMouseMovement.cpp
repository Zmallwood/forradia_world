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

#include "UpdateHeroMouseMovement.hpp"
#include "Theme1.Core.Devices/HeroDevice.hpp"
#include "Theme1.Core.Devices/MouseDevice.hpp"
#include "TileHoveringService.hpp"

namespace ForradiaWorld
{
    void UpdateHeroMouseMovement()
    {
        // Get the current time in milliseconds
        auto now = SDL_GetTicks();

        // Check if the left mouse button has been clicked (fired)
        auto leftMouseFired = _<MouseDevice>().GetLeftButton()->GetBeenFiredPickResult();

        // If the left mouse button was clicked, set the hero's destination to the hovered tile
        if (leftMouseFired)
        {
            // Get the tile currently hovered by the mouse
            auto hoveredTile = _<TileHoveringService>().GetHoveredTile();

            _<HeroDevice>().SetDestination(hoveredTile);
        }

        // Get the hero's current position and destination
        auto heroPos = _<HeroDevice>().GetPosition();
        auto destination = _<HeroDevice>().GetDestination();

        // If the destination is the same as the current position, clear the destination and return
        if (destination == heroPos)
        {
            _<HeroDevice>().SetDestination({ -1, -1 }); // Set destination to an invalid position
            return; // Exit as no movement is needed
        }

        // Ensure the hero can move only after the specified movement time interval
        if (now > _<HeroDevice>().GetTicksLastMovement() + 1000 / _<HeroDevice>().GetMovementSpeed()
            && destination.x != -1 && destination.y != -1)
        {
            // Calculate the difference in position (dx, dy) to move towards the destination
            auto dx = destination.x - heroPos.x;
            auto dy = destination.y - heroPos.y;

            // Move the hero horizontally based on dx
            if (dx < 0)
            {
                _<HeroDevice>().MoveLeft(); // Move left if destination is to the left
            }
            else if (dx > 0)
            {
                _<HeroDevice>().MoveRight(); // Move right if destination is to the right
            }

            // Move the hero vertically based on dy
            if (dy < 0)
            {
                _<HeroDevice>().MoveUp(); // Move up if destination is above
            }
            else if (dy > 0)
            {
                _<HeroDevice>().MoveDown(); // Move down if destination is below
            }

            // Update the time of the last movement to prevent continuous movement without interval
            _<HeroDevice>().SetTicksLastMovement(now);
        }
    }
}
