// Copyright 2025 Andreas Åkerberg

#include "Animal.hpp"

namespace ForradiaWorld
{
    Animal::Animal(std::string_view animalName)
        : m_type(Hash(animalName))
    {
    }
}
