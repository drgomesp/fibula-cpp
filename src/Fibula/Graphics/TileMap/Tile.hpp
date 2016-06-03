#ifndef FIBULA_TILE_HPP
#define FIBULA_TILE_HPP

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

                const unsigned int getWidth() const
                {
                    return width;
                }

                const unsigned int getHeight() const
                {
                    return height;
                }

                const unsigned int getPosition() const
                {
                    return position;
                }

                ~Tile()
                { }
            };
        }
    }
}


#endif //FIBULA_TILE_HPP
