#ifndef FIBULA_SDLRENDERERADAPTER_HPP
#define FIBULA_SDLRENDERERADAPTER_HPP

#include <memory>
#include <SDL2/SDL.h>

#include <Fibula/Graphics/Window/RendererAdapter.hpp>
#include <Fibula/Graphics/Window/WindowAdapter.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Window {
            namespace Adapter {
                class SDLRendererAdapter : public RendererAdapter
                {
                protected:
                    WindowAdapter *window;
                    SDL_Renderer *renderer;
                public:
                    SDLRendererAdapter(WindowAdapter *window);

                    ~SDLRendererAdapter();
                };
            }
        }
    }
}

#endif //FIBULA_SDLRENDERERADAPTER_HPP
