#include "GenerateWater.hpp"
#include "Theme0.Core.World/Tile.hpp"
#include "Theme0.Core.World/World.hpp"
#include "Theme0.Core.World/WorldArea.hpp"

namespace FW {
void GenerateWater()
{
    auto worldArea = _<World>().GetCurrentWorldArea();

    auto numLakes = 30 + rand() % 10;

    for (auto i = 0; i < numLakes; i++) {
        auto xCenter = rand() % 100;
        auto yCenter = rand() % 100;
        auto r = 3 + rand() % 8;

        for (auto y = yCenter - r; y <= yCenter + r; y++) {
            for (auto x = xCenter - r; x <= xCenter + r; x++) {
                if (x < 0 || y < 0 || x >= 100 || y >= 100) {
                    continue;
                }

                auto dx = x - xCenter;
                auto dy = y - yCenter;

                if (dx * dx + dy * dy <= r * r) {
                    auto tile = worldArea->GetTile(x, y);
                    tile->SetGround("GroundWater");
                }
            }
        }
    }
}
}
