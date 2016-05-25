#pragma once

#include <string>
#include <SDL2/SDL.h>

#include <Fibula/EventDispatcher/Dispatcher.h>
#include <boost/shared_ptr.hpp>

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
            boost::shared_ptr<Dispatcher> dispatcher;
        public:
            Window(const string &title, int width, int height, boost::shared_ptr<Dispatcher> dispatcher);
            ~Window();
            void handleEvents();
        };
    }
}
