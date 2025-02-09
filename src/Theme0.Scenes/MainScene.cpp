#include "MainScene.hpp"
#include "Theme0.ScenesLogic/UpdatePlayerMovement.hpp"
#include "Theme0.ScenesLogic/WorldView.hpp"
#include "Theme0.ScenesLogic/TileHovering.hpp"

namespace FW {
void MainScene::UpdateDerived()
{
    UpdatePlayerMovement();
    _<TileHovering>().Update();
}

void MainScene::RenderDerived() const
{
    _<WorldView>().Render();
}
}
