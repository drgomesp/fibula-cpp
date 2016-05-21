#include <SDL2/SDL.h>
#include "Kernel.h"

using namespace std;
using namespace Fibula::Core;

Kernel::Kernel()
{
    this->bootstrap();

    if (!this->booted) {
        throw runtime_error("Could not boot engine");
    }
}

void Kernel::bootstrap()
{
    try {
        unique_ptr<Dispatcher> eventDispatcher(new Dispatcher);
        this->eventDispatcher = eventDispatcher.get();
    } catch (exception const &e) {
        this->booted = false;
        return;
    }

    try {
        unique_ptr<Window> window(new Window("Fibula Engine :: v1.0.0", 640, 480));
        this->window = window.get();
    } catch (exception const &e) {
        this->booted = false;
        return;
    }

    this->booted = true;
}

void Kernel::run()
{
    if (!this->booted) {
        throw runtime_error("Failed to run engine because it was never booted");
    }

    SDL_Event event;
    this->running = true;

    while (this->running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                this->terminate();
            }
        }
    }
}

void Kernel::terminate()
{
    this->running = false;
}
