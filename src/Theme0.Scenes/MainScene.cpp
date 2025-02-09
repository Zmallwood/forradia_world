// Copyright 2025 Andreas Åkerberg

#include "MainScene.hpp"
#include "Theme0.ScenesLogic/TileHovering.hpp"
#include "Theme0.ScenesLogic/UpdateAnimalsMovement.hpp"
#include "Theme0.ScenesLogic/UpdateHeroKeyboardMovement.hpp"
#include "Theme0.ScenesLogic/UpdateHeroMouseMovement.hpp"
#include "Theme0.ScenesLogic/WorldView.hpp"

namespace ForradiaWorld
{
    void MainScene::UpdateDerived()
    {
        UpdateAnimalsMovement();
        UpdateHeroKeyboardMovement();
        UpdateHeroMouseMovement();
        _<TileHovering>().Update();
    }

    void MainScene::RenderDerived() const
    {
        _<WorldView>().Render();
    }
}
