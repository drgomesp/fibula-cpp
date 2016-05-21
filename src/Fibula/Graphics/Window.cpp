#include "Window.h"

#include <iostream>

Fibula::Graphics::Window::Window(const string &title, int width, int height)
        : title(title),
          width(width),
          height(height)
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

Fibula::Graphics::Window::~Window()
{

}
