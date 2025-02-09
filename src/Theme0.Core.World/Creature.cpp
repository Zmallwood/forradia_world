// Copyright 2025 Andreas Åkerberg

#include "Creature.hpp"

namespace ForradiaWorld
{

    Creature::Creature(std::string_view creatureName)
        : m_type(Hash(creatureName))
    {
    }

}
