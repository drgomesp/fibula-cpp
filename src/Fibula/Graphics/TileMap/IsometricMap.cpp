#include <Fibula/Graphics/TileMap/IsometricMap.hpp>

using namespace Fibula::Graphics::TileMap;

void IsometricMap::loadLayer(shared_ptr<Layer> layer, const vector<unsigned int> &data)
{
    shared_ptr<TileSet> tileSet = layer->getTileSet();

    auto it = data.begin();

    for (int c = 0; c < this->widthInTiles; ++c) {
        for (int r = 0; r < this->heightInTiles; ++r, it++) {
            unsigned int id = *it;
            ivec2 pixelCoordinates = tileSet->getCoordinatesFromId(id);

            int positionX = (r - c) * (tileSet->getTileWidth() / 2);
            int positionY = (r + c) * (tileSet->getTileHeight() / 4);

            positionX += tileSet->getTileWidth() * 2; // Adjust the map to the center of the view

            shared_ptr<Tile> tile = make_shared<Tile>(
                dvec2(tileSet->getTileWidth(), tileSet->getTileHeight()),
                dvec2(positionX, positionY),
                pixelCoordinates.x,
                pixelCoordinates.y,
                id,
                tileSet->getTexture()
            );

            layer->addTile(tile);
        }
    }

    this->layers.push_back(layer);
}

ivec2 IsometricMap::getTileCoordinatesFromPixelCoordinates(unsigned int x, unsigned int y)
{
    return ivec2(-1, -1);
}
