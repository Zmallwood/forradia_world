#include "IScene.hpp"

namespace fw {
void IScene::Update()
{
    UpdateDerived();
}

void IScene::Render() const
{
    RenderDerived();
}
}
