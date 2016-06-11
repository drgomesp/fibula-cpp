#include <Fibula/Graphics/Sprite.hpp>

using namespace Fibula::Graphics;

Sprite::Sprite(
    unsigned int width,
    unsigned int height,
    unsigned int offsetX,
    unsigned int offsetY,
    unsigned int x,
    unsigned int y,
    const shared_ptr<Texture> &texture)
    : width(width), height(height), offsetX(offsetX), offsetY(offsetY), texture(texture), x(x), y(y)
{
    sf::IntRect rect(offsetX, offsetY, width, height);
    sf::Sprite _sfml_sprite(*texture->get_sfml_texture(), rect);
    _sfml_sprite.setPosition(x, y);
    this->_sfml_sprite = make_shared<sf::Sprite>(_sfml_sprite);
}

void Sprite::draw(sf::RenderWindow *window)
{
    window->draw(*this->_sfml_sprite);
}
