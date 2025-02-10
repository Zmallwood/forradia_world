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

#include "UpdateHeroKeyboardMovement.hpp"
#include "Theme1.Core.Devices/HeroDevice.hpp"
#include "Theme1.Core.Devices/KeyboardDevice.hpp"

namespace ForradiaWorld
{
    void UpdateHeroKeyboardMovement()
    {
        // Check if specific arrow keys are pressed
        auto upPressed = _<KeyboardDevice>().KeyIsPressed(SDLK_UP);
        auto rightPressed = _<KeyboardDevice>().KeyIsPressed(SDLK_RIGHT);
        auto downPressed = _<KeyboardDevice>().KeyIsPressed(SDLK_DOWN);
        auto leftPressed = _<KeyboardDevice>().KeyIsPressed(SDLK_LEFT);

        // Get the current time in milliseconds
        auto now = SDL_GetTicks();

        // If enough time has passed since the last movement and a direction key is pressed
        if (now > _<HeroDevice>().GetTicksLastMovement() + 1000 / _<HeroDevice>().GetMovementSpeed()
            && (upPressed || rightPressed || downPressed || leftPressed))
        {

            // Move the hero in the corresponding direction if the key is pressed
            if (upPressed)
            {
                _<HeroDevice>().MoveUp(); // Move hero up
            }

            if (rightPressed)
            {
                _<HeroDevice>().MoveRight(); // Move hero right
            }

            if (downPressed)
            {
                _<HeroDevice>().MoveDown(); // Move hero down
            }

            if (leftPressed)
            {
                _<HeroDevice>().MoveLeft(); // Move hero left
            }

            // Update the hero's last movement time to prevent continuous movement
            _<HeroDevice>().SetTicksLastMovement(now);
        }
    }
}
