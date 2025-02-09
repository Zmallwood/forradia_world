#pragma once

namespace ForradiaWorld
{
    class PlayerDevice
    {
      public:
        void MoveUp();
        void MoveRight();
        void MoveDown();
        void MoveLeft();

        auto GetPosition() const
        {
            return m_position;
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

        auto GetDestination() const
        {
            return m_destination;
        }

        void SetDestination(Point value)
        {
            m_destination = value;
        }

      private:
        Point m_position { 50, 50 };
        Point m_destination { -1, -1 };
        int m_ticksLastMovement { 0 };
        float m_movementSpeed { 3.0f };
    };
}
