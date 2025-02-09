#include "ClearWithGrass.hpp"
#include "Theme0.Core.World/Tile.hpp"
#include "Theme0.Core.World/World.hpp"
#include "Theme0.Core.World/WorldArea.hpp"

namespace FW {
void ClearWithGrass()
{
    auto worldArea = _<World>().GetCurrentWorldArea();

    for (auto y = 0; y < 100; y++) {
        for (auto x = 0; x < 100; x++) {
            auto tile = worldArea->GetTile(x, y);
            tile->SetGround("GroundGrass");
        }
    }
}
}
