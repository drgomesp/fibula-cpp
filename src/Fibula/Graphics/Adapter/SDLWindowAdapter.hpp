#ifndef FIBULA_SDLWINDOWADAPTER_HPP
#define FIBULA_SDLWINDOWADAPTER_HPP

#include <SDL2/SDL.h>
#include <Fibula/Graphics/WindowAdapterInterface.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Adapter {
            class SDLWindowAdapter : public WindowAdapterInterface
            {
            private:
                SDL_Window *window;
            public:
                SDLWindowAdapter(
                        const std::string &title,
                        const int width,
                        const int height,
                        EventDispatcher::Dispatcher &dispatcher,
                        Core::Kernel *kernel
                );

                void handleEvents() override;
                std::string getName() override;

                ~SDLWindowAdapter();
            };
        }
    }
}

#endif //FIBULA_SDLWINDOWADAPTER_HPP
