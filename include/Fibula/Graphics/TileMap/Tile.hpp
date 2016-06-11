#pragma once

#include <Fibula/Graphics/Sprite.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            class Tile : public Sprite
            {
            protected:
                unsigned int id;
            public:
                Tile(
                    const shared_ptr<Texture> &texture,
                    unsigned int id,
                    unsigned int width,
                    unsigned int height,
                    unsigned int offsetX,
                    unsigned int offsetY,
                    unsigned int x,
                    unsigned int y
                );
            };
        }
    }
}
