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

#include "ScenesDevice.hpp"

#include "Theme1.Scenes/IntroScene.hpp"

#include "Theme1.Scenes/MainScene.hpp"

#include "Theme1.Scenes/WorldGenerationScene.hpp"

namespace ForradiaWorld
{
    /*
============= CLASS: ScenesDevice ============= */

    ScenesDevice::ScenesDevice()
    {
        AddScene(SceneNames::Intro, _<IntroScene>());
        AddScene(SceneNames::WorldGeneration, _<WorldGenerationScene>());
        AddScene(SceneNames::Main, _<MainScene>());

        GoToScene(SceneNames::Intro);
    }

    void ScenesDevice::AddScene(SceneNames sceneName, IScene& scene)
    {
        m_scenes.insert({ sceneName, scene });
    }

    void ScenesDevice::UpdateCurrentScene()
    {
        if (m_scenes.contains(m_currentScene))
        {
            m_scenes.at(m_currentScene).Update();
        }
    }

    void ScenesDevice::RenderCurrentScene() const
    {
        if (m_scenes.contains(m_currentScene))
        {
            m_scenes.at(m_currentScene).Render();
        }
    }

    void ScenesDevice::GoToScene(SceneNames sceneName)
    {
        m_currentScene = sceneName;
    }
}
