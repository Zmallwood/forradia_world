#include "IntroScene.hpp"
#include "Core/Rendering/ImageRenderer.hpp"
#include "Core/ScenesCore/SceneManager.hpp"

namespace FW {
void IntroScene::UpdateDerived()
{
    _<SceneManager>().GoToScene(SceneNames::WorldGeneration);
}

void IntroScene::RenderDerived() const
{
    _<ImageRenderer>().DrawImage("DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f });
    _<ImageRenderer>().DrawImage("ForradiaWorldLogo", { 0.3f, 0.2f, 0.4f, 0.2f });
}
}
