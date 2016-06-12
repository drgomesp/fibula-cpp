#include <Fibula/Graphics/TileMap/Layer.hpp>

using namespace std;
using namespace Fibula::Graphics::TileMap;

Layer::Layer(
    const string &name,
    unsigned int widthInTiles,
    unsigned int heightInTiles,
    bool visible,
    float opacity,
    const shared_ptr<TileSet> &tileSet
) : Drawable(dvec2(0, 0), position),
    name(name),
    widthInTiles(widthInTiles),
    heightInTiles(heightInTiles),
    visible(visible),
    opacity(opacity),
    tileSet(tileSet)
{
    Drawable::size.x = tileSet->getTileHeight() * heightInTiles;
    Drawable::size.y = tileSet->getTileWidth() * widthInTiles;
}

bool Layer::load(vector<unsigned int> data)
{
    vector<unsigned int>::iterator it = data.begin();

    for (int c = 0; c < this->widthInTiles; ++c) {
        for (int r = 0; r < this->heightInTiles; ++r, ++it) {
            // NOTE: Tiled Map Editor detail (when different than 0, start from 1)
            ivec2 coordinates = this->tileSet->getCoordinatesFromId((*it) == 0 ? (*it) : *it - 1);

            shared_ptr<Tile> tile = make_shared<Tile>(
                dvec2(this->tileSet->getTileWidth(), this->tileSet->getTileHeight()),
                dvec2(r * this->tileSet->getTileHeight(), c * this->tileSet->getTileWidth()),
                coordinates.x,
                coordinates.y,
                *it,
                this->tileSet->getTexture()
            );

            this->tiles.push_back(tile);
        }
    }

    return true;
}

void Layer::draw(shared_ptr<Fibula::Graphics::Window> window)
{
    for (shared_ptr<Tile> tile : this->tiles) {
        tile->draw(window);
    }
}
