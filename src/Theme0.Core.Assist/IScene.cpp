// Copyright 2025 Andreas Åkerberg

#include "IScene.hpp"

namespace ForradiaWorld
{
    void IScene::Update()
    {
        UpdateDerived();
    }

    void IScene::Render() const
    {
        RenderDerived();
    }
}
