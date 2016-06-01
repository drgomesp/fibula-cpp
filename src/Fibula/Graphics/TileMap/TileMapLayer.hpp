#ifndef FIBULA_TILEMAPLAYER_HPP
#define FIBULA_TILEMAPLAYER_HPP

#include <memory>
#include <string>
#include <vector>

#include <Fibula/Graphics/TileMap/Tile.hpp>
#include <Fibula/Graphics/TileMap/TileSet.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {

            using string = std::string;
            using vector = std::vector;
            using SPTile = std::shared_ptr<Tile>;
            using TileVector = vector<SPTile>;

            class TileMapLayer
            {
                const string &name;
                bool visible;
                TileVector *tiles;
                TileSet *tileSet;

            public:
                TileMapLayer(const string &name, bool visible, TileSet *tileSet)
                    : name(name),
                      visible(visible),
                      tileSet(tileSet)
                { }

                ~TileMapLayer()
                { }

                void createTilesFromVector(const vector<unsigned int> &data);
            };
        }
    }
}

#endif //FIBULA_TILEMAPLAYER_HPP
