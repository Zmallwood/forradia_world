#pragma once
#include "Core/ScenesCore/IScene.hpp"

namespace FW {
class MainScene : public IScene {
protected:
    void UpdateDerived() override;
    void RenderDerived() const override;
};
}
