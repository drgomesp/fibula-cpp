#ifndef FIBULA_TILESET_HPP
#define FIBULA_TILESET_HPP

#include <SDL2/SDL.h>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            class TileSet
            {
            protected:
                const unsigned int width;
                const unsigned int height;
                const unsigned int tileWidth;
                const unsigned int tileHeight;
                const SDL_Texture *texture;

            public:
                TileSet(const unsigned int width, const unsigned int height,
                        const unsigned int tileWidth, const unsigned int tileHeight,
                        const SDL_Texture *texture)
                    : width(width), height(height),
                      tileWidth(tileWidth),
                      tileHeight(tileHeight),
                      texture(texture)
                { }

                const unsigned int getWidth() const
                {
                    return width;
                }

                const unsigned int getHeight() const
                {
                    return height;
                }

                const unsigned int getTileWidth() const
                {
                    return tileWidth;
                }

                const unsigned int getTileHeight() const
                {
                    return tileHeight;
                }

                const SDL_Texture *getTexture() const
                {
                    return texture;
                }

                virtual ~TileSet()
                { }
            };
        }
    }
}

#endif //FIBULA_TILESET_HPP
