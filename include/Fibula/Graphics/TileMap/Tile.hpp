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
                    const dvec2 &size,
                    const dvec2 &position,
                    unsigned int offsetX,
                    unsigned int offsetY,
                    unsigned int id,
                    const shared_ptr<Texture> &texture
                );
            };
        }
    }
}
