#ifndef FIBULA_SFMLRENDERERADAPTER_HPP
#define FIBULA_SFMLRENDERERADAPTER_HPP

#include <Fibula/Graphics/Window/RendererAdapter.hpp>
#include <Fibula/Graphics/Window/WindowAdapter.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Window {
            namespace Adapter {
                class SFMLRendererAdapter : public RendererAdapter
                {
                public:
                    SFMLRendererAdapter()
                    { }

                    virtual void render(sf::RenderWindow *window) override;

                    ~SFMLRendererAdapter()
                    { }
                };
            }
        }
    }
}


#endif //FIBULA_SFMLRENDERERADAPTER_HPP
