#ifndef FIBULA_SFMLRENDERERADAPTER_HPP
#define FIBULA_SFMLRENDERERADAPTER_HPP

#include <Fibula/Graphics/Window/RendererAdapter.hpp>
#include <Fibula/Graphics/Window/WindowAdapter.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Window {
            namespace Adapter {
                class SFMLRendererAdapter : public RendererAdapter
                {
                    WindowAdapter *window;

                public:
                    SFMLRendererAdapter(WindowAdapter *window) : window(window)
                    { }

                    ~SFMLRendererAdapter()
                    { }
                };
            }
        }
    }
}


#endif //FIBULA_SFMLRENDERERADAPTER_HPP
