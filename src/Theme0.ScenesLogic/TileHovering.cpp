// Copyright 2025 Andreas Åkerberg

#include "TileHovering.hpp"
#include "Theme0.Core.Devices/HeroDevice.hpp"
#include "TileGridMath.hpp"

namespace ForradiaWorld
{
    void TileHovering::Update()
    {
        auto mousePosition = GetMousePosition();
        auto gridSize = GetGridSize();
        auto tileSize = GetTileSize();
        auto heroPos = _<HeroDevice>().GetPosition();
        auto relX = mousePosition.x / tileSize.w;
        auto relY = mousePosition.y / tileSize.h;
        auto xCoord = static_cast<int>(heroPos.x - (gridSize.w - 1) / 2 + relX);
        auto yCoord = static_cast<int>(heroPos.y - (gridSize.h - 1) / 2 + relY);
        m_hoveredTile = { xCoord, yCoord };
    }
}
