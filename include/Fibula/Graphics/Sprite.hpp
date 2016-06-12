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
            unsigned int offsetX;
            unsigned int offsetY;
            shared_ptr<Texture> texture;
            shared_ptr<const sf::Sprite> _sfml_sprite;
        public:
            Sprite(
                const dvec2 &size,
                const dvec2 &position,
                unsigned int offsetX,
                unsigned int offsetY,
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
