#ifndef FIBULA_TILE_HPP
#define FIBULA_TILE_HPP

#include <tkDecls.h>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            class Tile
            {
            protected:
                const unsigned int width = 32;
                const unsigned int height = 32;
                const unsigned int position = 0;

            public:
                Tile(const unsigned int width, const unsigned int height,
                     const unsigned int position) : width(width), height(height), position(position)
                { }

                ~Tile()
                { }
            };
        }
    }
}


#endif //FIBULA_TILE_HPP
