#include "TileMap.hpp"

using namespace Fibula::Graphics::TileMap;

void TileMap::addLayer(SPLayer layer)
{
    this->layers.push_back(layer);
}

