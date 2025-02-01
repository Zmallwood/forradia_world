#include "WorldView.hpp"
#include "Common/CanvasUtilities.hpp"
#include "Core/CoreGameObjects/Player.hpp"
#include "Core/Rendering/ImageRenderer.hpp"
#include "Core/WorldStructure/Tile.hpp"
#include "Core/WorldStructure/World.hpp"
#include "Core/WorldStructure/WorldArea.hpp"

namespace FW {
void WorldView::Render() const
{
    auto worldArea = _<World>().GetCurrentWorldArea();
    auto playerPosition = _<Player>().GetPosition();
    auto tileWidth = 0.05f;
    auto tileHeight = ConvertWidthToHeight(tileWidth);
    auto smallValue = 0.001f;
    for (auto y = 0; y < 11; y++) {
        for (auto x = 0; x < 11; x++) {
            auto coordX = playerPosition.x - 5 + x;
            auto coordY = playerPosition.y - 5 + y;

            if (coordX < 0 || coordY < 0 || coordX >= 100 || coordY >= 100) {
                continue;
            }

            auto tile = worldArea->GetTile(coordX, coordY);

            auto dest = RectF { x * tileWidth, y * tileHeight, tileWidth + smallValue, tileHeight + smallValue };

            auto ground = tile->GetGround();

            _<ImageRenderer>().DrawImage(ground, dest);

            if (x == 5 && y == 5) {
                _<ImageRenderer>().DrawImage("Player", dest);
            }
        }
    }
}
}
