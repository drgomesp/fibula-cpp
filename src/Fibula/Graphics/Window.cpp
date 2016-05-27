#include <Fibula/Graphics/Window.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEvent.hpp>

using namespace Fibula::Graphics;
using namespace Fibula::EventDispatcher;
using namespace Fibula::Bridge::EventDispatcher;

Window::Window(const std::string &title, int width, int height, Dispatcher &dispatcher)
        : title(title),
          width(width),
          height(height),
          dispatcher(dispatcher)
{
    SDL_Init(SDL_INIT_VIDEO);

    this->window = SDL_CreateWindow(
            this->title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            this->width,
            this->height,
            SDL_WINDOW_OPENGL
    );

    if (this->window == NULL) {
        throw std::runtime_error("Could not create window");
    }
}

Window::~Window()
{
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Window::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        boost::shared_ptr<SDLPayload> sdlPayload(new SDLPayload(event));
        SDLPayload *pSDLPayload = sdlPayload.get();

        boost::shared_ptr<SDLEvent> sdlEvent(new SDLEvent(*pSDLPayload));

        this->dispatcher.dispatchEvent("event.sdl", sdlEvent);
    }
}

