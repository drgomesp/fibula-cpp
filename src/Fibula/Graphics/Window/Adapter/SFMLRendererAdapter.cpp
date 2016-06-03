#include "SFMLRendererAdapter.hpp"

#include <Fibula/Graphics/TileMap/TileMap.hpp>
#include <SFML/Graphics/VertexArray.hpp>

using namespace std;
using namespace Fibula::Graphics::TileMap;
using namespace Fibula::Graphics::Window::Adapter;

void SFMLRendererAdapter::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    class TileMap tileMap("tileMap", 768, 480);

    vector<int> bushData = {
        375, 376,
        391, 392
    };

    sf::Texture texture;
    texture.loadFromFile("../../resources/mountain_landscape.png");

    TileSet tileSet(64, 64, 32, 32, &texture);
    TileMapLayer bush("Bush", true, &tileSet);

    bush.createTilesFromVector(bushData);
    tileMap.addLayer(make_shared<TileMapLayer>(bush));

    states.transform *= getTransform();
    states.texture = &texture;

    sf::VertexArray vertices;
    target.draw(vertices, states);
}


