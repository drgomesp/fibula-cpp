#pragma once

#include <memory>
#include <SFML/Graphics/Texture.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace std;

        class Texture
        {
            friend class Sprite;
        private:
            shared_ptr<const sf::Texture> _sfml_texture;

            const shared_ptr<const sf::Texture> &get_sfml_texture() const
            {
                return _sfml_texture;
            }
        public:
            Texture(const string &path);
            unsigned int getWidth();
            unsigned int getHeight();
        };
    }
}
