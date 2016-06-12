#ifndef FIBULA_TILEMAP_HPP
#define FIBULA_TILEMAP_HPP

#include <Fibula/Graphics/Drawable.hpp>
#include <Fibula/Graphics/TileMap/Layer.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            class Map : public Drawable
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

            public:
                virtual void loadLayer(shared_ptr<Layer> layer, vector<unsigned int> &data) = 0;
            };
        }
    }
}

#endif //FIBULA_TILEMAP_HPP
