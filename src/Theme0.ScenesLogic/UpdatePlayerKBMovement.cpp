// Copyright 2025 Andreas Åkerberg

#include "UpdatePlayerKBMovement.hpp"
#include "Theme0.Core.Devices/KeyboardDevice.hpp"
#include "Theme0.Core.Devices/PlayerDevice.hpp"

namespace ForradiaWorld
{
    void UpdatePlayerKBMovement()
    {
        auto upPressed = _<KeyboardDevice>().KeyIsPressed(SDLK_UP);
        auto rightPressed = _<KeyboardDevice>().KeyIsPressed(SDLK_RIGHT);
        auto downPressed = _<KeyboardDevice>().KeyIsPressed(SDLK_DOWN);
        auto leftPressed = _<KeyboardDevice>().KeyIsPressed(SDLK_LEFT);

        auto now = SDL_GetTicks();

        if (now > _<PlayerDevice>().GetTicksLastMovement() + 1000 / _<PlayerDevice>().GetMovementSpeed()
            && (upPressed || rightPressed || downPressed || leftPressed))
        {

            if (upPressed)
            {
                _<PlayerDevice>().MoveUp();
            }

            if (rightPressed)
            {
                _<PlayerDevice>().MoveRight();
            }

            if (downPressed)
            {
                _<PlayerDevice>().MoveDown();
            }

            if (leftPressed)
            {
                _<PlayerDevice>().MoveLeft();
            }

            _<PlayerDevice>().SetTicksLastMovement(now);
        }
    }
}
