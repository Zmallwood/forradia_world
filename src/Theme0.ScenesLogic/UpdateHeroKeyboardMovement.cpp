// Copyright 2025 Andreas Åkerberg

#include "UpdateHeroKeyboardMovement.hpp"

#include "Theme0.Core.Devices/KeyboardDevice.hpp"

#include "Theme0.Core.Devices/HeroDevice.hpp"

namespace ForradiaWorld
{

    void UpdateHeroKeyboardMovement()
    {
        auto upPressed = _<KeyboardDevice>().KeyIsPressed(SDLK_UP);
        auto rightPressed = _<KeyboardDevice>().KeyIsPressed(SDLK_RIGHT);
        auto downPressed = _<KeyboardDevice>().KeyIsPressed(SDLK_DOWN);
        auto leftPressed = _<KeyboardDevice>().KeyIsPressed(SDLK_LEFT);

        auto now = SDL_GetTicks();

        if (now > _<HeroDevice>().GetTicksLastMovement() + 1000 / _<HeroDevice>().GetMovementSpeed()
            && (upPressed || rightPressed || downPressed || leftPressed))
        {

            if (upPressed)
            {
                _<HeroDevice>().MoveUp();
            }

            if (rightPressed)
            {
                _<HeroDevice>().MoveRight();
            }

            if (downPressed)
            {
                _<HeroDevice>().MoveDown();
            }

            if (leftPressed)
            {
                _<HeroDevice>().MoveLeft();
            }

            _<HeroDevice>().SetTicksLastMovement(now);
        }
    }

}
