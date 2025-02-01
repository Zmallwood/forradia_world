#include "ClearWithGrass.hpp"
#include "Core/WorldStructure/Tile.hpp"
#include "Core/WorldStructure/World.hpp"
#include "Core/WorldStructure/WorldArea.hpp"

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
