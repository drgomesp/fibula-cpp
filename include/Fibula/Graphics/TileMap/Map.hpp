#ifndef FIBULA_TILEMAP_HPP
#define FIBULA_TILEMAP_HPP

#include <glm/vec2.hpp>
#include <Fibula/Events/Cargo.hpp>
#include <Fibula/Graphics/Drawable.hpp>
#include <Fibula/Graphics/TileMap/Layer.hpp>

namespace Fibula {
    namespace Graphics {

        using Cargo = Fibula::Events::Cargo;

        namespace TileMap {
            class Map : public Drawable, public Cargo
            {
            protected:
                const string &name;
                unsigned int widthInTiles;
                unsigned int heightInTiles;
                unsigned int tileWidth;
                unsigned int tileHeight;
                vector<shared_ptr<Layer>> layers;
            public:
                Map(
                    const string &name,
                    unsigned int widthInTiles,
                    unsigned int heightInTiles,
                    unsigned int tileWidth,
                    unsigned int tileHeight
                );

                virtual void draw(shared_ptr<Window> window) override;
                virtual void loadLayer(shared_ptr<Layer> layer, const vector<unsigned int> &data) = 0;
                virtual ivec2 getCoordinatesFromPixels(unsigned int x, unsigned int y) = 0;
            };
        }
    }
}

#endif //FIBULA_TILEMAP_HPP
