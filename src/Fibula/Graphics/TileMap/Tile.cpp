#include <Fibula/Graphics/TileMap/Layer.hpp>

using namespace std;
using namespace Fibula::Graphics;
using namespace Fibula::Graphics::TileMap;

Tile::Tile(
    const shared_ptr<Texture> &texture,
    unsigned int id,
    unsigned int width,
    unsigned int height,
    unsigned int offsetX,
    unsigned int offsetY,
    unsigned int x,
    unsigned int y
) : Sprite(width, height, offsetX, offsetY, texture), id(id), width(width), height(height), offsetX(offsetX), offsetY(offsetY), x(x), y(y)
{
}
