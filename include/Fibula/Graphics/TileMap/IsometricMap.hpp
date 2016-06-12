#ifndef PROJECT_ISOMETRICTILEMAP_HPP
#define PROJECT_ISOMETRICTILEMAP_HPP

#include <Fibula/Graphics/TileMap/Map.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            class IsometricMap : public Map
            {
            public:
                IsometricMap(
                    const string &name,
                    unsigned int widthInTiles,
                    unsigned int heightInTiles, unsigned int tileWidth,
                    unsigned int tileHeight
                ) : Map(name, widthInTiles, heightInTiles, tileWidth, tileHeight)
                {}

            public:
                virtual void loadLayer(shared_ptr<Layer> layer, vector<unsigned int> &data) override;
            };
        }
    }
}

#endif //PROJECT_ISOMETRICTILEMAP_HPP
