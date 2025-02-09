#include "WorldView.hpp"
#include "Theme0.Core.Devices/ImageDrawDevice.hpp"
#include "Theme0.Core.Devices/PlayerDevice.hpp"
#include "Theme0.Core.World/Tile.hpp"
#include "Theme0.Core.World/World.hpp"
#include "Theme0.Core.World/WorldArea.hpp"
#include "Theme0.ScenesLogic/TileGridMath.hpp"
#include "TileHovering.hpp"

namespace FW {
void WorldView::Render() const
{
    auto worldArea = _<World>().GetCurrentWorldArea();
    auto playerPosition = _<PlayerDevice>().GetPosition();
    auto gridSize = GetGridSize();
    auto tileSize = GetTileSize();
    auto hoveredTile = _<TileHovering>().GetHoveredTile();
    auto smallValue = 0.003f;
    for (auto y = 0; y < gridSize.h; y++) {
        for (auto x = 0; x < gridSize.w; x++) {
            auto coordX = playerPosition.x - (gridSize.w - 1) / 2 + x;
            auto coordY = playerPosition.y - (gridSize.h - 1) / 2 + y;

            if (coordX < 0 || coordY < 0 || coordX >= 100 || coordY >= 100) {
                continue;
            }

            auto tile = worldArea->GetTile(coordX, coordY);

            auto dest = RectF { x * tileSize.w, y * tileSize.h, tileSize.w + smallValue, tileSize.h + smallValue };

            auto ground = tile->GetGround();

            if (ground == Hash("GroundWater")) {
                auto animIndex = (SDL_GetTicks() % 1200) / 400;
                std::string animName = "GroundWater_" + std::to_string(animIndex);
                ground = Hash(animName);
            }

            _<ImageDrawDevice>().DrawImage(ground, dest);

            if (coordX == hoveredTile.x && coordY == hoveredTile.y) {
                _<ImageDrawDevice>().DrawImage("HoveredTile", dest);
            }

            auto object = tile->GetObject();

            _<ImageDrawDevice>().DrawImage(object, dest);

            if (coordX == playerPosition.x && coordY == playerPosition.y) {
                _<ImageDrawDevice>().DrawImage("Player", dest);
            }
        }
    }
}
}
