#ifndef FIBULA_WINDOWRENDERERADAPTER_HPP
#define FIBULA_WINDOWRENDERERADAPTER_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Window {
            class RendererAdapter
            {
            public:
                RendererAdapter()
                { }

                virtual void render(sf::RenderWindow *window) = 0;

                virtual ~RendererAdapter()
                { }
            };
        }
    }
}

#endif //FIBULA_RENDERERADAPTER_HPP
