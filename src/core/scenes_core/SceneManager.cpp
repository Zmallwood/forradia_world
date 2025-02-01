#include "SceneManager.hpp"
#include "IScene.hpp"

namespace FW {
SceneManager::SceneManager()
{
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
}
