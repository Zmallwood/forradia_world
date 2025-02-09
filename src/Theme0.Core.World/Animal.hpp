// Copyright 2025 Andreas Åkerberg

#pragma once

#include "Creature.hpp"

namespace ForradiaWorld
{
    class Animal : public Creature
    {
      public:
        Animal(std::string_view animalName);

        int GetType() const override
        {
            return m_type;
        }

      private:
        int m_type { 0 };
    };
}
