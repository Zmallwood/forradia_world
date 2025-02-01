#include "WorldView.hpp"
#include "Common/CanvasUtilities.hpp"
#include "Core/Rendering/ImageRenderer.hpp"

namespace FW {
void WorldView::Render() const
{
    auto tileWidth = 0.05f;
    auto tileHeight = ConvertWidthToHeight(tileWidth);
    auto smallValue = 0.001f;
    for (auto y = 0; y < 11; y++) {
        for (auto x = 0; x < 11; x++) {
            auto dest = RectF { x * tileWidth, y * tileHeight, tileWidth + smallValue, tileHeight + smallValue };

            _<ImageRenderer>().DrawImage("GroundGrass", dest);

            if (x == 5 && y == 5) {
                _<ImageRenderer>().DrawImage("Player", dest);
            }
        }
    }
}
}
