#ifndef FIBULA_SDLWINDOWADAPTER_HPP
#define FIBULA_SDLWINDOWADAPTER_HPP

#include <SDL2/SDL.h>
#include <Fibula/Graphics/Window/WindowAdapterInterface.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Window {
            namespace Adapter {
                class SDLWindowAdapter : public WindowAdapterInterface
                {
                protected:
                    SDL_Window *window;
                    std::shared_ptr<RendererAdapter> rendererAdapter;
                public:
                    SDLWindowAdapter(
                        const std::string &title,
                        const unsigned int width,
                        const unsigned int height,
                        EventDispatcher::Dispatcher &dispatcher,
                        Core::Kernel &kernel
                    );

                    virtual void handleEvents() override;
                    virtual void render() override;

                    inline SDL_Window *getWindowImpl()
                    {
                        return this->window;
                    }

                    ~SDLWindowAdapter();
                };
            }
        }
    }
}

#endif //FIBULA_SDLWINDOWADAPTER_HPP
