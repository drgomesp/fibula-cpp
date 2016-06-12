#include <Fibula/Graphics/Sprite.hpp>

using namespace Fibula::Graphics;

Sprite::Sprite(
    const dvec2 &size,
    const dvec2 &position,
    unsigned int offsetX, unsigned int offsetY,
    const shared_ptr<Texture> &texture
) : Drawable(size, position), offsetX(offsetX), offsetY(offsetY), texture(texture)
{
    sf::IntRect rect(offsetX, offsetY, size.x, size.y);
    sf::Sprite _sfml_sprite(*texture->get_sfml_texture(), rect);
    _sfml_sprite.setPosition(position.x, position.y);
    this->_sfml_sprite = make_shared<sf::Sprite>(_sfml_sprite);
}

void Sprite::draw(shared_ptr<Window> window)
{
    window->get_sfml_window()->draw(*this->_sfml_sprite);
}
