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

                virtual ~TileSet()
                { }
            };
        }
    }
}

#endif //FIBULA_TILESET_HPP
