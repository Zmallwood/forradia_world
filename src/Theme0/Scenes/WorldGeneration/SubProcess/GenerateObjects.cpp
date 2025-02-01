#include "GenerateObjects.hpp"
#include "Core/WorldStructure/Tile.hpp"
#include "Core/WorldStructure/World.hpp"
#include "Core/WorldStructure/WorldArea.hpp"

namespace FW {
void GenerateObjects()
{
    auto worldArea = _<World>().GetCurrentWorldArea();

    auto numTree1s = 100 + rand() % 20;

    for (auto i = 0; i < numTree1s; i++) {
        auto x = rand() % 100;
        auto y = rand() % 100;

        auto tile = worldArea->GetTile(x, y);
        tile->SetObject("ObjectTree1");
    }
}
}
