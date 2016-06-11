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
        protected:
            unsigned int width;
            unsigned int height;
            unsigned int offsetX;
            unsigned int offsetY;
            shared_ptr<const sf::Sprite> _sfml_sprite;
            shared_ptr<Texture> texture;
        public:
            Sprite(
                unsigned int width,
                unsigned int height,
                unsigned int offsetX,
                unsigned int offsetY,
                const shared_ptr<Texture> &texture
            );

            virtual void draw(sf::RenderWindow *window) override;
        };
    }
}
