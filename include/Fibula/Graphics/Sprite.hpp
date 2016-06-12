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
            unsigned int x;
            unsigned int y;
            shared_ptr<Texture> texture;
            shared_ptr<const sf::Sprite> _sfml_sprite;
        public:
            Sprite(
                unsigned int width,
                unsigned int height,
                unsigned int offsetX,
                unsigned int offsetY,
                unsigned int x,
                unsigned int y,
                const shared_ptr<Texture> &texture
            );

            const shared_ptr<Texture> &getTexture() const
            {
                return texture;
            }

            virtual void draw(shared_ptr<Window> window) override;
        };
    }
}
