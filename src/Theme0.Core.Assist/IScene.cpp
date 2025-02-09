// Copyright 2025 Andreas Åkerberg

#include "IScene.hpp"

namespace ForradiaWorld
{

    void IScene::Update()
    {
        /*\
Update the parts in the inheriting class.
*/
        UpdateDerived();
    }

    void IScene::Render() const
    {
        /*\
Render the parts in the inheriting class.
*/
        RenderDerived();
    }

}
