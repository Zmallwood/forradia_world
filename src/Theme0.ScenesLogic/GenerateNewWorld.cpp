#include "GenerateNewWorld.hpp"
#include "ClearWorldWithGrass.hpp"
#include "GenerateObjectsForWorld.hpp"
#include "GenerateWaterForWorld.hpp"

namespace ForradiaWorld
{
    void GenerateNewWorld()
    {
        ClearWorldWithGrass();
        GenerateWaterForWorld();
        GenerateObjectsForWorld();
    }
}
