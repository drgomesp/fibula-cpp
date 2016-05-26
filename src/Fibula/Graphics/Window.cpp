#include "Window.h"
#include <Fibula/Bridge/EventDispatcher/SDLEvent.h>
#include <boost/format.hpp>

using namespace Fibula::Graphics;
using namespace Fibula::Bridge::EventDispatcher;

Window::Window(const string &title, int width, int height, Dispatcher dispatcher)
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
        throw runtime_error("Could not create window");
    }
}

Window::~Window()
{

}

void Window::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        boost::shared_ptr<SDLEvent> sdlEvent(
            new SDLEvent(boost::str(boost::format("event.sdl.%1%") % event.type), event.type)
        );

        this->dispatcher.dispatchEvent(sdlEvent.get());
    }
}

