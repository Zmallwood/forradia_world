#pragma once
#include "Theme0.Core.Assist/IScene.hpp"

namespace ForradiaWorld
{
    class IntroScene : public IScene
    {
      public:
      protected:
        void UpdateDerived() override;
        void RenderDerived() const override;
    };
}
