#include <Fibula/Graphics/Sprite.hpp>

using namespace Fibula::Graphics;

Sprite::Sprite(const shared_ptr<Texture> &texture) : texture(texture)
{
    sf::Sprite _sfml_sprite;
    _sfml_sprite.setTexture(*texture->get_sfml_texture());
    this->_sfml_sprite = make_shared<sf::Sprite>(_sfml_sprite);
}

void Sprite::draw(sf::RenderWindow *window)
{
    window->draw(*this->_sfml_sprite);
}
