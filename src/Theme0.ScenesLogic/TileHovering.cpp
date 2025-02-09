// Copyright 2025 Andreas Åkerberg

#include "TileHovering.hpp"
#include "Theme0.Core.Devices/PlayerDevice.hpp"
#include "TileGridMath.hpp"

namespace ForradiaWorld
{
    void TileHovering::Update()
    {
        auto mousePosition = GetMousePosition();
        auto gridSize = GetGridSize();
        auto tileSize = GetTileSize();
        auto playerPos = _<PlayerDevice>().GetPosition();
        auto relX = mousePosition.x / tileSize.w;
        auto relY = mousePosition.y / tileSize.h;
        auto xCoord = static_cast<int>(playerPos.x - (gridSize.w - 1) / 2 + relX);
        auto yCoord = static_cast<int>(playerPos.y - (gridSize.h - 1) / 2 + relY);
        m_hoveredTile = { xCoord, yCoord };
    }
}
