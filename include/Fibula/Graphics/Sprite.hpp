#pragma once

#include <glm/vec2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <Fibula/Graphics/Drawable.hpp>
#include <Fibula/Graphics/Texture.hpp>
#include <Fibula/Graphics/Window.hpp>

namespace Fibula {
    namespace Graphics {

        using namespace std;
        using namespace glm;

        class Sprite : public Drawable
        {
        private:
            shared_ptr<const sf::Sprite> _sfml_sprite;
        protected:
            shared_ptr<Texture> texture;
        public:
            Sprite(const shared_ptr<Texture> &texture);
            virtual void draw(sf::RenderWindow *window) override;
        };
    }
}
