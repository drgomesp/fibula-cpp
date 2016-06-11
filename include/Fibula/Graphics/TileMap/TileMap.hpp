#ifndef FIBULA_TILEMAP_HPP
#define FIBULA_TILEMAP_HPP

#include <Fibula/Graphics/Drawable.hpp>
#include <Fibula/Graphics/TileMap/Layer.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            class TileMap : public Drawable
            {
            protected:
                const string &name;
                int width;
                int height;
                vector<shared_ptr<Layer>> layers;
            public:
                TileMap(
                    const string &name,
                    int width,
                    int height
                ) : name(name), width(width), height(height)
                {}

                virtual void draw(sf::RenderWindow *window) override;
                void addLayer(shared_ptr<Layer> layer, vector<int> data);
            };
        }
    }
}

#endif //FIBULA_TILEMAP_HPP
