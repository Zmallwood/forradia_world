#include "IntroScene.hpp"
#include "Theme0.Core.Devices/ImageDrawDevice.hpp"
#include "Theme0.Core.Devices/ScenesDevice.hpp"

namespace FW {
void IntroScene::UpdateDerived()
{
    _<ScenesDevice>().GoToScene(SceneNames::WorldGeneration);
}

void IntroScene::RenderDerived() const
{
    _<ImageDrawDevice>().DrawImage("DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f });
    _<ImageDrawDevice>().DrawImage("ForradiaWorldLogo", { 0.3f, 0.2f, 0.4f, 0.2f });
}
}
