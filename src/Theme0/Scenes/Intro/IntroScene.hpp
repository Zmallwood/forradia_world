#pragma once
#include "Core/ScenesCore/IScene.hpp"

namespace FW {
class IntroScene : public IScene {
protected:
    void UpdateDerived();
    void RenderDerived() const;
};
}
