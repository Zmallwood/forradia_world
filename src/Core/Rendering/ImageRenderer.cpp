#include "ImageRenderer.hpp"
#include "Core/Assets/ImageLoader.hpp"
#include "Core/SDLDevice/SDLDevice.hpp"

namespace FW {
void ImageRenderer::DrawImage(int imageNameHash, RectF destination) const
{
    auto image = _<ImageLoader>().GetImage(imageNameHash);
    auto canvasSize = GetCanvasSize();

    auto xPx = static_cast<int>(destination.x * canvasSize.w);
    auto yPx = static_cast<int>(destination.y * canvasSize.h);
    auto widthPx = static_cast<int>(destination.w * canvasSize.w);
    auto heightPx = static_cast<int>(destination.h * canvasSize.h);

    auto sdlRectangle = SDL_Rect { xPx, yPx, widthPx, heightPx };

    SDL_RenderCopy(_<SDLDevice>().GetRenderer().get(), image.get(), nullptr, &sdlRectangle);
}

void ImageRenderer::DrawImage(std::string_view imageName, RectF destination) const
{
    DrawImage(Hash(imageName), destination);
}
}
