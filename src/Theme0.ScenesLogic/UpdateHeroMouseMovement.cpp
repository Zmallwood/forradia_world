// Copyright 2025 Andreas Åkerberg

#include "UpdateHeroMouseMovement.hpp"

#include "Theme0.Core.Assist/MouseButton.hpp"

#include "Theme0.Core.Devices/MouseDevice.hpp"

#include "Theme0.Core.Devices/HeroDevice.hpp"

#include "TileHovering.hpp"

namespace ForradiaWorld
{

    void UpdateHeroMouseMovement()
    {
        auto now = SDL_GetTicks();

        auto leftMouseFired = _<MouseDevice>().GetLeftButton()->GetBeenFiredPickResult();
        auto hoveredTile = _<TileHovering>().GetHoveredTile();

        if (leftMouseFired)
        {
            _<HeroDevice>().SetDestination(hoveredTile);
        }

        auto destination = _<HeroDevice>().GetDestination();
        auto heroPos = _<HeroDevice>().GetPosition();

        if (destination.x == heroPos.x && destination.y == heroPos.y)
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
