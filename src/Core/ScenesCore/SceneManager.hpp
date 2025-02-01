#pragma once
#include "Theme0/Scenes/SceneNames.hpp"

namespace FW {
class IScene;

class SceneManager {
public:
    SceneManager();

    void UpdateCurrentScene();
    void RenderCurrentScene() const;
    void GoToScene(SceneNames sceneName);

private:
    void AddScene(SceneNames sceneName, IScene& scene);

    std::map<SceneNames, IScene&> m_scenes;
    SceneNames m_currentScene { 0 };
};
}
