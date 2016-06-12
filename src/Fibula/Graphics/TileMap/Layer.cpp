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

void Layer::draw(shared_ptr<Fibula::Graphics::Window> window)
{
    for (shared_ptr<Tile> tile : this->tiles) {
        tile->draw(window);
    }
}

const shared_ptr<TileSet> &Layer::getTileSet() const
{
    return tileSet;
}

void Layer::addTile(shared_ptr<Tile> tile)
{
    this->tiles.push_back(tile);
}
