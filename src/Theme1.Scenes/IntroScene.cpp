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

#include "IntroScene.hpp"
#include "Theme1.Core.Devices/ImageDrawDevice.hpp"
#include "Theme1.Core.Devices/ScenesServiceDevice.hpp"

namespace ForradiaWorld
{
    void IntroScene::UpdateDerived()
    {
        // Transition to the next scene (WorldGeneration) when updating the Intro scene.
        _<ScenesServiceDevice>().GoToScene(SceneNames::WorldGeneration);
    }

    void IntroScene::RenderDerived() const
    {
        // Draw the background image for the scene, covering the full canvas.
        _<ImageDrawDevice>().DrawImage("DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f });

        // Draw the logo at a specific position on the screen (top-center of the canvas).
        _<ImageDrawDevice>().DrawImage("ForradiaWorldLogo", { 0.3f, 0.2f, 0.4f, 0.2f });
    }
}
