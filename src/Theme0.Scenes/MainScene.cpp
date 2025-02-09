#include "MainScene.hpp"
#include "Theme0.ScenesLogic/UpdatePlayerKBMovement.hpp"
#include "Theme0.ScenesLogic/UpdatePlayerMouseMovement.hpp"
#include "Theme0.ScenesLogic/WorldView.hpp"
#include "Theme0.ScenesLogic/TileHovering.hpp"

namespace FW {
void MainScene::UpdateDerived()
{
    UpdatePlayerKBMovement();
    UpdatePlayerMouseMovement();
    _<TileHovering>().Update();
}

void MainScene::RenderDerived() const
{
    _<WorldView>().Render();
}
}
