#pragma once

#include <string>
#include <SDL2/SDL.h>

using namespace std;

namespace Fibula {
    namespace Graphics {
        class Window
        {
        private:
            string title;
            int width;
            int height;
            SDL_Window *window;
        public:
            Window(const string &title, int width, int height);
            ~Window();
        };
    }
}
