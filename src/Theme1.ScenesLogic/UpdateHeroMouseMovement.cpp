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
#include "Theme1.Core.Devices/MouseDevice.hpp"
#include "Theme1.Core.Devices/HeroDevice.hpp"
#include "TileHoveringService.hpp"

namespace ForradiaWorld
{
    void UpdateHeroMouseMovement()
    {
        auto now = SDL_GetTicks();

        auto leftMouseFired = _<MouseDevice>().GetLeftButton()->GetBeenFiredPickResult();
        auto hoveredTile = _<TileHoveringService>().GetHoveredTile();

        if (leftMouseFired)
        {
            _<HeroDevice>().SetDestination(hoveredTile);
        }

        auto destination = _<HeroDevice>().GetDestination();
        auto heroPos = _<HeroDevice>().GetPosition();

        if (destination == heroPos)
        {
            _<HeroDevice>().SetDestination({ -1, -1 });

            return;
        }

        if (now > _<HeroDevice>().GetTicksLastMovement() + 1000 / _<HeroDevice>().GetMovementSpeed()
            && destination.x != -1 && destination.y != -1)
        {

            auto dx = destination.x - heroPos.x;
            auto dy = destination.y - heroPos.y;

            if (dx < 0)
            {
                _<HeroDevice>().MoveLeft();
            }
            else if (dx > 0)
            {
                _<HeroDevice>().MoveRight();
            }

            if (dy < 0)
            {
                _<HeroDevice>().MoveUp();
            }
            else if (dy > 0)
            {
                _<HeroDevice>().MoveDown();
            }

            _<HeroDevice>().SetTicksLastMovement(now);
        }
    }
}
