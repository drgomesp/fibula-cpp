#ifndef PROJECT_ORTHOGONALTILEMAP_HPP
#define PROJECT_ORTHOGONALTILEMAP_HPP

#include <Fibula/Graphics/TileMap/Map.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            class OrthogonalMap : public Map
            {
            public:
                OrthogonalMap(
                    const string &name,
                    unsigned int widthInTiles,
                    unsigned int heightInTiles, unsigned int tileWidth,
                    unsigned int tileHeight
                ) : Map(name, widthInTiles, heightInTiles, tileWidth, tileHeight)
                {}

            public:
                virtual void loadLayer(shared_ptr<Layer> layer, const vector<unsigned int> &data) override;
                virtual ivec2 getCoordinatesFromPixels(unsigned int x, unsigned int y) override;
            };
        }
    }
}

#endif //PROJECT_ORTHOGONALTILEMAP_HPP
