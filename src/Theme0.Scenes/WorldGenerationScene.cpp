#include "WorldGenerationScene.hpp"
#include "Theme0.Core.Devices/ScenesDevice.hpp"
#include "Theme0.ScenesLogic/GenerateNewWorld.hpp"

namespace ForradiaWorld
{
    void WorldGenerationScene::UpdateDerived()
    {
        GenerateNewWorld();
        _<ScenesDevice>().GoToScene(SceneNames::Main);
    }

    void WorldGenerationScene::RenderDerived() const
    {
    }
}
