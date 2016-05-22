#include "Window.h"

#include <boost/shared_ptr.hpp>
#include <Fibula/Bridge/EventDispatcher/SDLEventListener.h>

using namespace Fibula::Graphics;

Window::Window(const string &title, int width, int height, Dispatcher *dispatcher)
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
        boost::shared_ptr<SDLEvent> sdlEvent(new SDLEvent(event.type));
        this->dispatcher->dispatchEvent(boost::get_pointer(sdlEvent));
    }
}

