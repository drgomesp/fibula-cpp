#include <Fibula/Graphics/TileMap/Map.hpp>

using namespace std;
using namespace Fibula::Graphics::TileMap;

Map::Map(
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

void Map::loadLayer(shared_ptr<Layer> layer, vector<unsigned int> data)
{
    if (layer->load(data)) {
        this->layers.push_back(layer);
    }
}

void Map::draw(shared_ptr<Fibula::Graphics::Window> window)
{
    for (auto layer : this->layers) {
        layer->draw(window);
    }
}
