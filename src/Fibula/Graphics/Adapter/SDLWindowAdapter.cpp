#include <Fibula/Graphics/Adapter/SDLWindowAdapter.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEvent.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEventListener.hpp>

using namespace Fibula::Core;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Graphics::Adapter;
using namespace Fibula::Bridge::EventDispatcher;

SDLWindowAdapter::SDLWindowAdapter(
        const std::string &title,
        const int width,
        const int height,
        Dispatcher &dispatcher,
        Core::Kernel *kernel
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
        throw std::runtime_error("Failed to create SDL window");
    }

    boost::shared_ptr<SDLEventListener> sdlEventListener(new SDLEventListener(kernel));
    this->dispatcher.addListener("event.sdl.*", sdlEventListener);
}

void SDLWindowAdapter::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        boost::shared_ptr<SDLPayload> sdlPayload(new SDLPayload(event));
        SDLPayload *pSDLPayload = sdlPayload.get();

        boost::shared_ptr<SDLEvent> sdlEvent(new SDLEvent(*pSDLPayload));

        this->dispatcher.dispatchEvent("event.sdl", sdlEvent);
    }
}

std::string SDLWindowAdapter::getName()
{
    return this->name;
}

SDLWindowAdapter::~SDLWindowAdapter()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
