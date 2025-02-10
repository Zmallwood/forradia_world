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

#include "WorldGenerationScene.hpp"
#include "Theme1.Core.Devices/ScenesServiceDevice.hpp"
#include "Theme1.ScenesLogic/GenerateNewWorld.hpp"

namespace ForradiaWorld
{
    void WorldGenerationScene::UpdateDerived()
    {
        // Generate a new world when the scene is updated.
        GenerateNewWorld();

        // Transition to the main scene once the world is generated.
        _<ScenesServiceDevice>().GoToScene(SceneNames::Main);
    }

    void WorldGenerationScene::RenderDerived() const
    {
        // No rendering is performed in this scene for now.
    }
}
