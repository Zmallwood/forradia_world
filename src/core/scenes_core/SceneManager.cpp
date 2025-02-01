#include "SceneManager.hpp"
#include "IScene.hpp"
#include "theme_0/scenes/intro/IntroScene.hpp"

namespace FW {
SceneManager::SceneManager()
{
    AddScene("IntroScene", _<IntroScene>());
}

void SceneManager::AddScene(std::string_view sceneName, IScene& scene)
{
    m_scenes.insert({ Hash(sceneName), scene });
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

void SceneManager::GoToScene(std::string_view sceneName)
{
    m_currentScene = Hash(sceneName);
}
}
