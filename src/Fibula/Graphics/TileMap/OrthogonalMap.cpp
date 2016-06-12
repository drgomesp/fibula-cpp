#include <Fibula/Graphics/TileMap/OrthogonalMap.hpp>

using namespace Fibula::Graphics::TileMap;

void OrthogonalMap::loadLayer(shared_ptr<Layer> layer, const vector<unsigned int> &data)
{
    shared_ptr<TileSet> tileSet = layer->getTileSet();

    auto it = data.begin();

    for (int c = 0; c < this->widthInTiles; ++c) {
        for (int r = 0; r < this->heightInTiles; ++r, it++) {
            unsigned int id = *it;
            ivec2 pixelCoordinates = tileSet->getCoordinatesFromId(id == 0 ? id : id - 1);

            int positionX = r * tileSet->getTileHeight();
            int positionY = c * tileSet->getTileWidth();

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

int OrthogonalMap::getTileFromCoordinates(unsigned int x, unsigned int y)
{
    return ((x / this->tileHeight) * (y / this->tileWidth));
}
