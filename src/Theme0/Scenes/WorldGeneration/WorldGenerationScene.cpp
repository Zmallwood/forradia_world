#include "WorldGenerationScene.hpp"
#include "Core/ScenesCore/SceneManager.hpp"
#include "SubProcess/GenerateNewWorld.hpp"

namespace FW {
void WorldGenerationScene::UpdateDerived()
{
    GenerateNewWorld();
    _<SceneManager>().GoToScene(SceneNames::Main);
}

void WorldGenerationScene::RenderDerived() const
{
}
}
