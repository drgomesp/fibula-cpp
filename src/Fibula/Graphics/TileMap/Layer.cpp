#include <Fibula/Graphics/TileMap/Layer.hpp>

using namespace std;
using namespace Fibula::Graphics::TileMap;

bool Layer::load(vector<int> data)
{
    vector<int>::iterator it = data.begin();

    for (int c = 0; c < this->width; ++c) {
        for (int r = 0; r < this->height; ++r, ++it) {
            // NOTE: Tiled Map Editor detail (start from 1 instead of 0)
            ivec2 coordinates = this->tileSet->getCoordinatesFromId(*it - 1);

            shared_ptr<Tile> tile = make_shared<Tile>(
                this->tileSet->getTexture(),
                *it,
                this->tileSet->getTileWidth(),
                this->tileSet->getTileHeight(),
                coordinates.x,
                coordinates.y,
                r * this->tileSet->getTileHeight(),
                c * this->tileSet->getTileWidth()
            );

            this->tiles.push_back(tile);
        }
    }

    return true;
}

void Layer::draw(sf::RenderWindow *window)
{
    for (shared_ptr<Tile> tile : this->tiles) {
        tile->draw(window);
    }
}
