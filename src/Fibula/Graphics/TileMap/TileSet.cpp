#include <math.h>

#include <Fibula/Graphics/Texture.hpp>
#include <Fibula/Graphics/TileMap/TileSet.hpp>

using namespace std;
using namespace Fibula::Graphics;
using namespace Fibula::Graphics::TileMap;

ivec2 TileSet::getCoordinatesFromId(unsigned int id)
{
    ivec2 coordinates(0, 0);
    int tilesPerColumn = this->texture->getWidth() / this->tileWidth;

    int row = (int) floor(id / tilesPerColumn);
    int col = (int) floor(id % tilesPerColumn);

    coordinates.x = col * this->tileWidth;
    coordinates.y = row * this->tileHeight;

    return coordinates;
}

unsigned int TileSet::getTileWidth() const
{
    return tileWidth;
}

unsigned int TileSet::getTileHeight() const
{
    return tileHeight;
}

const shared_ptr<Texture> &TileSet::getTexture() const
{
    return texture;
}
