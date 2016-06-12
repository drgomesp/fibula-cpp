#ifndef FIBULA_TILEMAPLAYER_HPP
#define FIBULA_TILEMAPLAYER_HPP

#include <string>
#include <vector>

#include <Fibula/Graphics/Drawable.hpp>
#include <Fibula/Graphics/TileMap/Tile.hpp>
#include <Fibula/Graphics/TileMap/TileSet.hpp>

namespace Fibula {
    namespace Graphics {
        namespace TileMap {

            using namespace std;

            class Layer : public Drawable
            {
            protected:
                const string &name;
                unsigned int width;
                unsigned int height;
                bool visible = true;
                float opacity = 1.0f;
                vector<shared_ptr<Tile>> tiles;
                shared_ptr<TileSet> tileSet;
            public:
                Layer(
                    const string &name,
                    unsigned int width,
                    unsigned int height,
                    bool visible,
                    float opacity,
                    const shared_ptr<TileSet> &tileSet
                ) : name(name), width(width), height(height), visible(visible), opacity(opacity), tileSet(tileSet)
                {}

                bool load(vector<unsigned int> data);

                virtual void draw(shared_ptr<Window> window) override;

                shared_ptr<TileSet> getTileSet()
                {
                    return this->tileSet;
                }

                const vector<shared_ptr<Tile>> &getTiles() const
                {
                    return tiles;
                }
            };
        }
    }
}

#endif //PROJECT_TILEMAPLAYER_HPP
