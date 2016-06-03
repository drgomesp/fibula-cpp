#ifndef FIBULA_WINDOWRENDERERADAPTER_HPP
#define FIBULA_WINDOWRENDERERADAPTER_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Window {
            class RendererAdapter : public sf::Drawable, public sf::Transformable
            {
            public:
                RendererAdapter()
                { }

                virtual ~RendererAdapter()
                { }
            };
        }
    }
}

#endif //FIBULA_RENDERERADAPTER_HPP
