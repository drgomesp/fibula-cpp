#ifndef FIBULA_TILEMAP_HPP
#define FIBULA_TILEMAP_HPP

#include <memory>
#include <string>
#include <vector>

#include <Fibula/Graphics/TileMap/TileMapLayer.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {

            using string = std::string;
            using SPLayer= std::shared_ptr<TileMapLayer>;
            using LayerVector = std::vector<SPLayer>;

            class TileMap
            {
            protected:
                const string &name;
                unsigned int width;
                unsigned int height;
                LayerVector layers;

            public:
                TileMap(const string &name, unsigned int width, unsigned int height)
                    : name(name),
                      width(width),
                      height(height)
                { }

                ~TileMap()
                { }
            };
        }
    }

}


#endif //FIBULA_TILEMAP_HPP
