// Copyright 2025 Andreas Åkerberg

#pragma once

namespace ForradiaWorld
{
    class Creature
    {
      public:
        Creature(std::string_view creatureName);

        virtual ~Creature() { }

        int GetType() const
        {
            return m_type;
        }
        auto GetTicksLastMovement() const
        {
            return m_ticksLastMovement;
        }
        void SetTicksLastMovement(int value)
        {
            m_ticksLastMovement = value;
        }
        auto GetMovementSpeed() const
        {
            return m_movementSpeed;
        }

      private:
        int m_type { 0 };
        int m_ticksLastMovement { 0 };
        float m_movementSpeed { 1.0f };
    };
}
