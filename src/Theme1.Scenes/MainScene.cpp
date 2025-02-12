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

#include "MainScene.hpp"
#include "Theme1.ScenesLogic/TileHoveringService.hpp"
#include "Theme1.ScenesLogic/UpdateAnimalsMovement.hpp"
#include "Theme1.ScenesLogic/UpdateHeroKeyboardMovement.hpp"
#include "Theme1.ScenesLogic/UpdateHeroMouseMovement.hpp"
#include "Theme1.ScenesLogic/WorldViewService.hpp"

namespace ForradiaWorld
{
    void MainScene::UpdateDerived()
    {
        // Update the movement of all animals in the scene
        UpdateAnimalsMovement();

        // Update the hero's movement based on keyboard input
        UpdateHeroKeyboardMovement();

        // Update the hero's movement based on mouse input
        UpdateHeroMouseMovement();

        // Update the tile hovering service (handles hovering interactions on the map)
        _<TileHoveringService>().Update();
    }

    void MainScene::RenderDerived() const
    {
        // Render the world view (responsible for drawing the game world, including tiles, creatures, etc.)
        _<WorldViewService>().Render();
    }
}
