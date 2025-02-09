#include "ImageDrawDevice.hpp"
#include "Theme0.Core.Devices/ImageLoadDevice.hpp"
#include "Theme0.Core.Devices/SDLDevice.hpp"

namespace FW {
void ImageDrawDevice::DrawImage(int imageNameHash, RectF destination) const
{
    auto image = _<ImageLoadDevice>().GetImage(imageNameHash);
    auto canvasSize = GetCanvasSize();

    auto xPx = static_cast<int>(destination.x * canvasSize.w);
    auto yPx = static_cast<int>(destination.y * canvasSize.h);
    auto widthPx = static_cast<int>(destination.w * canvasSize.w);
    auto heightPx = static_cast<int>(destination.h * canvasSize.h);

    auto sdlRectangle = SDL_Rect { xPx, yPx, widthPx, heightPx };

    SDL_RenderCopy(_<SDLDevice>().GetRenderer().get(), image.get(), nullptr, &sdlRectangle);
}

void ImageDrawDevice::DrawImage(std::string_view imageName, RectF destination) const
{
    DrawImage(Hash(imageName), destination);
}
}
