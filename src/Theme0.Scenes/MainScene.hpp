#pragma once
#include "Theme0.Core.Assist/IScene.hpp"

namespace FW {
class MainScene : public IScene {
protected:
    void UpdateDerived() override;
    void RenderDerived() const override;
};
}
