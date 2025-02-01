#include "MainScene.hpp"
#include "SubProcess/UpdatePlayerMovement.hpp"
#include "SubProcess/WorldView/WorldView.hpp"

namespace FW {
void MainScene::UpdateDerived()
{
    UpdatePlayerMovement();
}

void MainScene::RenderDerived() const
{
    _<WorldView>().Render();
}
}
