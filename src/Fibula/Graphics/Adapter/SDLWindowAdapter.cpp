#include <Fibula/Graphics/Adapter/SDLWindowAdapter.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEvent.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEventListener.hpp>

using namespace Fibula::Core;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Graphics::Adapter;
using namespace Fibula::Bridge::EventDispatcher;

SDLWindowAdapter::SDLWindowAdapter(
        const std::string &title,
        const unsigned int width,
        const unsigned int height,
        Dispatcher &dispatcher,
        Core::Kernel &kernel
) : WindowAdapterInterface("Graphics::Adapter::SDLWindowAdapter", title, width, height, dispatcher, kernel)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("Failed to initialize SDL");
    }

    this->window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_OPENGL
    );

    if (this->window == NULL) {
        SDL_Quit();
        throw std::runtime_error("Failed to create SDL window");
    }

    SDLEventListener listener(&kernel);
    this->dispatcher.addListener<SDLEventListener>("event.sdl.*", &listener);
}

void SDLWindowAdapter::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        std::shared_ptr<SDLPayload> payload = std::make_shared<SDLPayload>(event);
        SDLEvent e(*payload);

        this->dispatcher.dispatchEvent<SDLEvent>("event.sdl", e);
    }
}

SDLWindowAdapter::~SDLWindowAdapter()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
