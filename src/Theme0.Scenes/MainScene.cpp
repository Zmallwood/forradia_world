// Copyright 2025 Andreas Åkerberg

#include "MainScene.hpp"
#include "Theme0.ScenesLogic/TileHovering.hpp"
#include "Theme0.ScenesLogic/UpdatePlayerKBMovement.hpp"
#include "Theme0.ScenesLogic/UpdatePlayerMouseMovement.hpp"
#include "Theme0.ScenesLogic/WorldView.hpp"

namespace ForradiaWorld
{
    void MainScene::UpdateDerived()
    {
        UpdatePlayerKBMovement();
        UpdatePlayerMouseMovement();
        _<TileHovering>().Update();
    }

    void MainScene::RenderDerived() const
    {
        _<WorldView>().Render();
    }
}
