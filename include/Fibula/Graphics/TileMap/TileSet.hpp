#pragma once

#include <glm/vec2.hpp>

#include <Fibula/Graphics/Sprite.hpp>
#include <Fibula/Graphics/Texture.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            enum class Projection
            {
                ORTHOGONAL = 1,
                ISOMETRIC = 2
            };

            using namespace glm;

            class TileSet : public Sprite
            {
            protected:
                Projection projection;
                unsigned int tileWidth;
                unsigned int tileHeight;
            public:
                TileSet(
                    Projection projection,
                    const shared_ptr<Texture> &texture,
                    unsigned int tileWidth,
                    unsigned int tileHeight
                ) : Sprite(dvec2(texture->getWidth(), texture->getHeight()), dvec2(0, 0), 0, 0, texture),
                    projection(projection), tileWidth(tileWidth), tileHeight(tileHeight)
                {}

                ivec2 getCoordinatesFromId(unsigned int id);
                unsigned int getTileWidth() const;
                unsigned int getTileHeight() const;
                Projection getProjection() const;
            };
        }
    }
}
