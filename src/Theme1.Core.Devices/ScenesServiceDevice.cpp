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

#include "ScenesServiceDevice.hpp"
#include "Theme1.Scenes/IntroScene.hpp"
#include "Theme1.Scenes/MainScene.hpp"
#include "Theme1.Scenes/WorldGenerationScene.hpp"

namespace ForradiaWorld
{
    ScenesServiceDevice::ScenesServiceDevice()
    {
        // Add predefined scenes to the scene manager
        AddScene(SceneNames::Intro, _<IntroScene>());
        AddScene(SceneNames::WorldGeneration, _<WorldGenerationScene>());
        AddScene(SceneNames::Main, _<MainScene>());

        // Start by setting the initial scene to the Intro scene
        GoToScene(SceneNames::Intro);
    }

    void ScenesServiceDevice::AddScene(SceneNames sceneName, IScene& scene)
    {
        // Insert the scene into the scene map with its associated name
        m_scenes.insert({ sceneName, scene });
    }

    void ScenesServiceDevice::UpdateCurrentScene()
    {
        // Check if the current scene exists in the map
        if (m_scenes.contains(m_currentScene))
        {
            // Call the Update function of the current scene
            m_scenes.at(m_currentScene).Update();
        }
    }

    void ScenesServiceDevice::RenderCurrentScene() const
    {
        // Check if the current scene exists in the map
        if (m_scenes.contains(m_currentScene))
        {
            // Call the Render function of the current scene
            m_scenes.at(m_currentScene).Render();
        }
    }

    void ScenesServiceDevice::GoToScene(SceneNames sceneName)
    {
        // Change the current active scene
        m_currentScene = sceneName;
    }

}
