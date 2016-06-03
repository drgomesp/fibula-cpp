#ifndef FIBULA_TILEMAP_HPP
#define FIBULA_TILEMAP_HPP

#include <memory>
#include <string>
#include <vector>

#include <Fibula/Graphics/TileMap/TileMapLayer.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {

            using string = std::string;
            using SPLayer= std::shared_ptr<TileMapLayer>;
            using LayerVector = std::vector<SPLayer>;

            class TileMap : sf::Drawable
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

                virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override
                { }

                void addLayer(SPLayer layer);

                const LayerVector &getLayers() const
                {
                    return layers;
                }

                ~TileMap()
                { }
            };
        }
    }

}


#endif //FIBULA_TILEMAP_HPP
