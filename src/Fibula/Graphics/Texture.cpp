#include <exception>
#include <Fibula/Graphics/Texture.hpp>

using namespace Fibula::Graphics;

Texture::Texture(const string &path)
{
    sf::Texture _sfml_texture;

    if (!_sfml_texture.loadFromFile(path)) {
        throw new std::invalid_argument("Failed to load image.\n");
    }

    this->_sfml_texture = std::make_shared<sf::Texture>(_sfml_texture);
}

unsigned int Texture::getWidth()
{
    return this->_sfml_texture->getSize().x;
}

unsigned int Texture::getHeight()
{
    return this->_sfml_texture->getSize().y;
}
