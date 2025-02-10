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

#pragma once

#include "Theme1.Core.Inheritable/IScene.hpp"

namespace ForradiaWorld
{
    /**
    * @class MainScene
    * @brief Represents the main scene in the game, where the core gameplay occurs.
    *
    * In this scene, the player controls the hero and interacts with the game world.
    * This class manages the update and render loops specific to the main gameplay scene.
    */
    class MainScene : public IScene
    {
      protected:
        /**
        * @brief Updates the game state for the main scene.
        *
        * This function handles updating the movement of animals, the hero's movement
        * based on both keyboard and mouse input, and any interactions with the tile hovering service.
        *
        * @see UpdateAnimalsMovement()
        * @see UpdateHeroKeyboardMovement()
        * @see UpdateHeroMouseMovement()
        * @see TileHoveringService::Update()
        */
        void UpdateDerived() override;

        /**
        * @brief Renders the main scene to the screen.
        *
        * This function is responsible for rendering the world view, which includes
        * the game world and all elements that need to be displayed.
        *
        * @see WorldViewService::Render()
        */
        void RenderDerived() const override;
    };
}
