// Copyright 2025 Andreas Åkerberg

#include "ScenesDevice.hpp"

#include "Theme0.Scenes/IntroScene.hpp"

#include "Theme0.Scenes/MainScene.hpp"

#include "Theme0.Scenes/WorldGenerationScene.hpp"

namespace ForradiaWorld
{

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
