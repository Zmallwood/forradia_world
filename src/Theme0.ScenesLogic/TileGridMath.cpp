#include "TileGridMath.hpp"
#include "Theme0.Core.Configuration/GameProperties.hpp"

namespace ForradiaWorld
{
    Size GetGridSize()
    {
        auto numGridRows = _<GameProperties>().k_numGridRows;
        auto aspectRatio = GetAspectRatio();
        auto numGridCols = static_cast<int>(numGridRows * aspectRatio) + 1;
        return { numGridCols, numGridRows };
    }

    SizeF GetTileSize()
    {
        auto numGridRows = _<GameProperties>().k_numGridRows;
        auto tileHeight = 1.0f / numGridRows;
        auto tileWidth = ConvertHeightToWidth(tileHeight);
        return { tileWidth, tileHeight };
    }
}
