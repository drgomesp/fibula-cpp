#ifndef FIBULA_SDLRENDERERADAPTER_HPP
#define FIBULA_SDLRENDERERADAPTER_HPP

#include <memory>
#include <SDL2/SDL.h>

#include <Fibula/Graphics/Window/RendererAdapter.hpp>
#include <Fibula/Graphics/Window/WindowAdapterInterface.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Window {

            class SDLRendererAdapter : public RendererAdapter
            {
            protected:
                WindowAdapterInterface *window;
                SDL_Renderer *renderer;
            public:
                SDLRendererAdapter(WindowAdapterInterface *window);

                ~SDLRendererAdapter();
            };
        }
    }
}

#endif //FIBULA_SDLRENDERERADAPTER_HPP
