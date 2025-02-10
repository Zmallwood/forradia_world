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
    * @class IntroScene
    * @brief Represents the intro scene in the game, derived from the IScene base class.
    *
    * The IntroScene handles the update and render operations specific to the introductory scene,
    * transitioning to the next scene once the intro is completed.
    */
    class IntroScene : public IScene
    {
      protected:
        /**
        * @brief Updates the state of the IntroScene.
        *
        * This function is called every frame and performs any updates necessary
        * for the intro scene, such as transitioning to the WorldGeneration scene.
        */
        void UpdateDerived() override;

        /**
        * @brief Renders the IntroScene to the screen.
        *
        * This function is called every frame and draws the elements specific to
        * the intro scene, such as background images and the logo.
        */
        void RenderDerived() const override;
    };
}
