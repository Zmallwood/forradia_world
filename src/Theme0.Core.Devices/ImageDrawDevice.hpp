#pragma once

namespace FW {
class ImageDrawDevice {
public:
    void DrawImage(int imageNameHash, RectF destination) const;
    void DrawImage(std::string_view imageName, RectF destination) const;
};
}
