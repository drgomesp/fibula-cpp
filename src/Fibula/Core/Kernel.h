#pragma once

#include <Fibula/Graphics/Window.h>
#include <Fibula/EventDispatcher/Dispatcher.h>

using namespace Fibula::Graphics;
using namespace Fibula::EventDispatcher;

namespace Fibula {
    namespace Core {
        class Kernel
        {
        private:
            bool running = false;
            bool booted = false;

            Dispatcher *eventDispatcher;
            Window *window;
        public:
            Kernel();
            void bootstrap();
            void run();
            void terminate();
        };
    }
}
