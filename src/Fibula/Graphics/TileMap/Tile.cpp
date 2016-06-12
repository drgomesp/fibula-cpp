#include <Fibula/Graphics/TileMap/Layer.hpp>

using namespace std;
using namespace Fibula::Graphics;
using namespace Fibula::Graphics::TileMap;

Tile::Tile(
    const dvec2 &size,
    const dvec2 &position,
    unsigned int offsetX,
    unsigned int offsetY,
    unsigned int id,
    const shared_ptr<Texture> &texture
) : Sprite(size, position, offsetX, offsetY, texture), id(id)
{}
