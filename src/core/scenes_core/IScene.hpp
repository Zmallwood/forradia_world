#pragma once

namespace fw {
class IScene {
public:
    void Update();
    void Render() const;

protected:
    virtual void UpdateDerived() { }
    virtual void RenderDerived() const { }
};
}
