// Copyright 2025 Andreas Åkerberg

#include "GenerateNewWorld.hpp"
#include "ClearWorldWithGrass.hpp"
#include "GenerateObjectsForWorld.hpp"
#include "GenerateWaterForWorld.hpp"
#include "GenerateAnimalsForWorld.hpp"

namespace ForradiaWorld
{
    void GenerateNewWorld()
    {
        ClearWorldWithGrass();
        GenerateWaterForWorld();
        GenerateObjectsForWorld();
        GenerateAnimalsForWorld();
    }
}
