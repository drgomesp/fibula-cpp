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

                    ~SFMLRendererAdapter()
                    { }
                private:
                    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
                };
            }
        }
    }
}


#endif //FIBULA_SFMLRENDERERADAPTER_HPP
