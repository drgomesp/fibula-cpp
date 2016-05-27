#ifndef FIBULA_SFMLWINDOWADAPTER_HPP
#define FIBULA_SFMLWINDOWADAPTER_HPP

#include <SFML/Graphics.hpp>
#include <Fibula/Graphics/WindowAdapterInterface.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Adapter {
            class SFMLWindowAdapter : public WindowAdapterInterface
            {
            protected:
                std::shared_ptr<sf::RenderWindow> window;
            public:
                SFMLWindowAdapter(
                    const std::string &title,
                    const unsigned int width,
                    const unsigned int height,
                    EventDispatcher::Dispatcher &dispatcher,
                    Core::Kernel &kernel
                );

                void handleEvents() override;

                ~SFMLWindowAdapter();
            };
        }
    }
}

#endif //FIBULA_SFMLWINDOWADAPTER_HPP
