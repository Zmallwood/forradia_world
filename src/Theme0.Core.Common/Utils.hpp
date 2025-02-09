// Copyright 2025 Andreas Åkerberg

#pragma once

namespace ForradiaWorld
{
    template <class T>
    T& _()
    {
        static T instance;

        return instance;
    }

    int Hash(std::string_view text);

    class SDLDeleter
    {
      public:
        void operator()(SDL_Window* window) const;

        void operator()(SDL_Renderer* renderer) const;

        void operator()(SDL_Surface* surface) const;

        void operator()(SDL_Texture* texture) const;

        void operator()(TTF_Font* font) const;
    };

    std::string Replace(std::string_view text, char replaced, char replacedWith);

    std::string GetFileExtension(std::string_view path);

    std::string GetFileNameNoExtension(std::string_view path);

    PointF GetMousePosition();

    Size GetCanvasSize();

    float GetAspectRatio();

    float ConvertWidthToHeight(float width);

    float ConvertHeightToWidth(float height);
}
