#include "MainScene.hpp"
#include "SubProcess/WorldView/WorldView.hpp"

namespace FW {
void MainScene::UpdateDerived()
{
}

void MainScene::RenderDerived() const
{
    _<WorldView>().Render();
}
}
