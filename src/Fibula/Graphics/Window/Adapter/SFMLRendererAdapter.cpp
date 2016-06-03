#include "SFMLRendererAdapter.hpp"

#include <Fibula/Graphics/TileMap/TileMap.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

using namespace std;
using namespace Fibula::Graphics::TileMap;
using namespace Fibula::Graphics::Window::Adapter;


void SFMLRendererAdapter::render(sf::RenderWindow *window)
{
//    class TileMap tileMap("tileMap", 768, 480);
//
//    vector<int> bushData = {
//        375, 376,
//        391, 392
//    };
//
//    sf::Texture texture;
//    texture.loadFromFile("../../resources/mountain_landscape.png");
//
//    TileSet tileSet(64, 64, 32, 32, &texture);
//    TileMapLayer bush("Bush", true, &tileSet);
//
//    bush.createTilesFromVector(bushData);
//    tileMap.addLayer(make_shared<TileMapLayer>(bush));
//
//    states.transform *= getTransform();
//    states.texture = &texture;
//
//    sf::VertexArray vertices;
//    target.draw(vertices, states);

    cout << "SFMLRendererAdapter::draw()" << endl;

    sf::Texture texture;

    if (!texture.loadFromFile("../../resources/mountain_landscape.png")) {
        cout << "Error loading texture file" << endl;
    }

    sf::Sprite spriteSheet;
    spriteSheet.setTexture(texture);

    spriteSheet.setTextureRect(sf::IntRect(32, 32, 32, 32));
    window->draw(spriteSheet);
}
