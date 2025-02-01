#pragma once

namespace FW {
class ImageRenderer {
public:
    void DrawImage(int imageNameHash, RectF destination) const;
    void DrawImage(std::string_view imageName, RectF destination) const;
};
}
