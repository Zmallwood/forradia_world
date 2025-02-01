#pragma once
#include "Core/ScenesCore/IScene.hpp"

namespace FW {
class MainScene : public IScene {
protected:
    void UpdateDerived();
    void RenderDerived() const;
};
}
