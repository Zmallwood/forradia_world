#pragma once

namespace FW {
class IScene;

class SceneManager {
public:
    SceneManager();

    void UpdateCurrentScene();
    void RenderCurrentScene() const;

private:
    std::map<int, IScene&> m_scenes;
    int m_currentScene { 0 };
};
}
