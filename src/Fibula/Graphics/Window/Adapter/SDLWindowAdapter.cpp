#include <Fibula/Core/Kernel.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEvent.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEventListener.hpp>
#include <Fibula/Graphics/Window/Adapter/SDLWindowAdapter.hpp>
#include <Fibula/Graphics/Window/Adapter/SDLRendererAdapter.hpp>

using namespace std;
using namespace Fibula::Core;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Graphics::Window::Adapter;
using namespace Fibula::Bridge::EventDispatcher;

SDLWindowAdapter::SDLWindowAdapter(
    const string &title,
    const unsigned int width,
    const unsigned int height,
    Dispatcher &dispatcher,
    Kernel &kernel
) : WindowAdapterInterface("Graphics::Adapter::SDLWindowAdapter", title, width, height, dispatcher, kernel)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw runtime_error("Failed to initialize SDL");
    }

    this->window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_OPENGL
    );

    this->rendererAdapter = std::make_shared<SDLRendererAdapter>(this);

    if (NULL == this->window) {
        SDL_Quit();
        throw runtime_error("Failed to create SDL window");
    }

    shared_ptr<SDLEventListener> listener = make_shared<SDLEventListener>(&kernel);
    this->dispatcher.addListener("event.sdl.*", listener);
}

void SDLWindowAdapter::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        shared_ptr<SDLPayload> payload = make_shared<SDLPayload>(event);
        shared_ptr<const SDLEvent> e = make_shared<const SDLEvent>(*payload);

        this->dispatcher.dispatchEvent("event.sdl", e);
    }
}

SDLWindowAdapter::~SDLWindowAdapter()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void SDLWindowAdapter::render()
{

}


