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
    * @class WorldGenerationScene
    * @brief A scene responsible for generating the world.
    *
    * This scene handles the logic for generating a new world and transitioning
    * to the main scene once the generation is complete. It extends from the
    * base class IScene.
    */
    class WorldGenerationScene : public IScene
    {
      protected:
        /**
        * @brief Updates the scene, generating a new world and transitioning to the main scene.
        *
        * This function is called during the update phase of the scene and performs the
        * world generation and transitions to the next scene once the world is ready.
        */
        void UpdateDerived() override;

        /**
        * @brief Renders the scene.
        *
        * This function is called during the render phase, but no rendering is performed
        * in this particular scene.
        */
        void RenderDerived() const override;
    };
}
