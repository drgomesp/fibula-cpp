#include <Fibula/Graphics/TileMap/TileMap.hpp>

using namespace std;
using namespace Fibula::Graphics::TileMap;

TileMap::TileMap(
    const string &name,
    unsigned int widthInTiles,
    unsigned int heightInTiles,
    unsigned int tileWidth,
    unsigned int tileHeight
) : name(name),
    widthInTiles(widthInTiles),
    heightInTiles(heightInTiles),
    tileWidth(tileWidth),
    tileHeight(tileHeight),
    Drawable(dvec2(0, 0), dvec2(0, 0))
{
    Drawable::size.x = tileHeight * heightInTiles;
    Drawable::size.y = tileWidth * widthInTiles;
}

void TileMap::addLayer(shared_ptr<Layer> layer, vector<unsigned int> data)
{
    if (layer->load(data)) {
        this->layers.push_back(layer);
    }
}

void TileMap::draw(shared_ptr<Fibula::Graphics::Window> window)
{
    for (shared_ptr<Layer> layer : this->layers) {
        layer->draw(window);
    }
}
