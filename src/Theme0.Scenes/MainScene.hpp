// Copyright 2025 Andreas Åkerberg

#pragma once

#include "Theme0.Core.Assist/IScene.hpp"

namespace ForradiaWorld
{
    class MainScene : public IScene
    {
      protected:
        void UpdateDerived() override;
        void RenderDerived() const override;
    };
}
