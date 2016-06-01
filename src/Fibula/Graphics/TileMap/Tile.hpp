#ifndef FIBULA_TILE_HPP
#define FIBULA_TILE_HPP

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            class Tile
            {
            protected:
                const unsigned int width;
                const unsigned int height;

            public:
                Tile(const unsigned int width, const unsigned int height)
                    : width(width),
                      height(height)
                { }

                virtual ~Tile()
                { }
            };
        }
    }
}


#endif //FIBULA_TILE_HPP
