#ifndef FIBULA_SDLWINDOWADAPTER_HPP
#define FIBULA_SDLWINDOWADAPTER_HPP

#include <SDL2/SDL.h>
#include <Fibula/Graphics/Adapter/WindowAdapterInterface.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Adapter {
            class SDLWindowAdapter : public WindowAdapterInterface
            {
            private:
                const std::string title = "[Fibula Engine :: v1.0.0]";
                const int width = 640;
                const int height = 480;
                SDL_Window *window;
            public:
                SDLWindowAdapter(const std::string &title, const int width, const int height,
                                 EventDispatcher::Dispatcher &dispatcher);

                void create(
                        const std::string &title,
                        const int width,
                        const int height,
                        EventDispatcher::Dispatcher &dispatcher) override;

                void handleEvents() override;
                std::string getName() override;

                ~SDLWindowAdapter();
            };
        }
    }
}

#endif //FIBULA_SDLWINDOWADAPTER_HPP
