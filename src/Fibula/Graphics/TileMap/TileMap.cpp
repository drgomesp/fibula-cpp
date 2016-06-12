#include <Fibula/Graphics/TileMap/TileMap.hpp>

using namespace std;
using namespace Fibula::Graphics::TileMap;

void TileMap::addLayer(shared_ptr<Layer> layer, vector<unsigned int> data)
{
    if (layer->load(data)) {
        this->layers.push_back(layer);
    }
}

void TileMap::draw(sf::RenderWindow *window)
{
    for (shared_ptr<Layer> layer : this->layers) {
        layer->draw(window);
    }
}
