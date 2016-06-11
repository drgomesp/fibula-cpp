#pragma once

#include <glm/vec2.hpp>

#include <Fibula/Graphics/Sprite.hpp>
#include <Fibula/Graphics/Texture.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {

            using namespace glm;

            class TileSet : public Sprite
            {
            protected:
                unsigned int tileWidth;
                unsigned int tileHeight;
            public:
                TileSet(
                    const shared_ptr<Texture> &texture,
                    unsigned int tileWidth,
                    unsigned int tileHeight
                ) : Sprite(texture->getWidth(), texture->getHeight(), 0, 0, texture),
                    tileWidth(tileWidth), tileHeight(tileHeight)
                {}

                ivec2 getCoordinatesFromId(unsigned int id);
                unsigned int getTileWidth() const;
                unsigned int getTileHeight() const;

                const shared_ptr<Texture> &getTexture() const;
            };
        }
    }
}
