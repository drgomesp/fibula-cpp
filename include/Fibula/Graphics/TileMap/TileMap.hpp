#ifndef FIBULA_TILEMAP_HPP
#define FIBULA_TILEMAP_HPP

#include <Fibula/Graphics/Drawable.hpp>
#include <Fibula/Graphics/TileMap/Layer.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {
            enum class Projection
            {
                ORTHOGONAL = 1,
                ISOMETRIC = 2
            };

            class TileMap : public Drawable
            {
            protected:
                Projection projection;
                const string &name;
                int width;
                int height;
                vector<shared_ptr<Layer>> layers;
            public:
                TileMap(
                    Projection projection,
                    const string &name,
                    int width,
                    int height
                ) : projection(projection), name(name), width(width), height(height)
                {}

                virtual void draw(shared_ptr<Window> window) override;

            public:
                void addLayer(shared_ptr<Layer> layer, vector<unsigned int> data);
            };
        }
    }
}

#endif //FIBULA_TILEMAP_HPP
