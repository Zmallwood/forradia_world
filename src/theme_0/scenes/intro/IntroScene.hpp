#pragma once
#include "core/scenes_core/IScene.hpp"

namespace FW {
class IntroScene : public IScene {
protected:
    void UpdateDerived();
    void RenderDerived() const;
};
}
