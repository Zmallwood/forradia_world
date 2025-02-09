#pragma once

namespace ForradiaWorld
{
    class IScene
    {
      public:
        void Update();
        void Render() const;

      protected:
        virtual void UpdateDerived() { }
        virtual void RenderDerived() const { }
    };
}
