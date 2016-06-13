#pragma once

#include <memory>

namespace Fibula {
    namespace Events {
        class Dispatcher;
    }

    namespace Graphics {
        class Window;
    }
}

#include <Fibula/Events/Dispatcher.hpp>
#include <Fibula/Graphics/Window.hpp>

namespace Fibula {
    namespace Core {

        using namespace std;
        using Dispatcher = Fibula::Events::Dispatcher;
        using Window = Fibula::Graphics::Window;

        class Kernel
        {
        public:
            bool running = false;
        protected:
            bool booted = false;
            shared_ptr<Window> window;
            shared_ptr<Dispatcher> dispatcher;

        public:
            void run();
            void terminate();

            const shared_ptr<Window> &getWindow() const;

            /* Game specific functions */
            virtual void bootstrap();
            virtual void registerListeners();
            virtual void handleEvents();
            virtual void handleInputs();
            virtual void update();
        };
    }
}
