#pragma once

#include <string>
#include <SDL2/SDL.h>

#include <Fibula/EventDispatcher/Dispatcher.h>

using namespace std;
using namespace Fibula::EventDispatcher;

namespace Fibula {
    namespace Graphics {
        class Window
        {
        private:
            string title;
            int width;
            int height;
            SDL_Window *window;
            Dispatcher *dispatcher;
        public:
            Window(const string &title, int width, int height, Dispatcher *dispatcher);
            ~Window();
            void handleEvents();
        };
    }
}
