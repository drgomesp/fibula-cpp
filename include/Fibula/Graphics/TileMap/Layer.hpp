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
                unsigned int widthInTiles;
                unsigned int heightInTiles;
                bool visible = true;
                float opacity = 1.0f;
                vector<shared_ptr<Tile>> tiles;
                shared_ptr<TileSet> tileSet;
            public:
                Layer(
                    const string &name,
                    unsigned int widthInTiles,
                    unsigned int heightInTiles,
                    bool visible,
                    float opacity,
                    const shared_ptr<TileSet> &tileSet
                );

                bool load(vector<unsigned int> data);
                virtual void draw(shared_ptr<Window> window) override;
            private:
                void loadIsometric(vector<unsigned int> data);
                void loadOrthogonal(vector<unsigned int> data);
            };
        }
    }
}

#endif //PROJECT_TILEMAPLAYER_HPP
