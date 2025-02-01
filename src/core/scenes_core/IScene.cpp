#include "IScene.hpp"

namespace FW {
void IScene::Update()
{
    UpdateDerived();
}

void IScene::Render() const
{
    RenderDerived();
}
}
