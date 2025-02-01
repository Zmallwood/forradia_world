#pragma once

namespace FW {
class IScene;

class SceneManager {
public:
    SceneManager();

    void UpdateCurrentScene();
    void RenderCurrentScene() const;
    void GoToScene(std::string_view sceneName);

private:
    void AddScene(std::string_view sceneName, IScene& scene);

    std::map<int, IScene&> m_scenes;
    int m_currentScene { 0 };
};
}
