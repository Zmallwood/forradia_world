#include "SceneManager.hpp"
#include "IScene.hpp"
#include "Theme0/Scenes/Intro/IntroScene.hpp"

namespace FW {
SceneManager::SceneManager()
{
    AddScene(SceneNames::Intro, _<IntroScene>());

    GoToScene(SceneNames::Intro);
}

void SceneManager::AddScene(SceneNames sceneName, IScene& scene)
{
    m_scenes.insert({ sceneName, scene });
}

void SceneManager::UpdateCurrentScene()
{
    if (m_scenes.contains(m_currentScene)) {
        m_scenes.at(m_currentScene).Update();
    }
}

void SceneManager::RenderCurrentScene() const
{
    if (m_scenes.contains(m_currentScene)) {
        m_scenes.at(m_currentScene).Render();
    }
}

void SceneManager::GoToScene(SceneNames sceneName)
{
    m_currentScene = sceneName;
}
}
