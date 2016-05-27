#ifndef FIBULA_WINDOWADAPTERINTERFACE_HPP
#define FIBULA_WINDOWADAPTERINTERFACE_HPP

#include <string>
#include <boost/shared_ptr.hpp>

namespace Fibula {
    namespace Core {
        class Kernel;
    }
}

#include <Fibula/Core/Kernel.hpp>
#include <Fibula/EventDispatcher/Dispatcher.hpp>

namespace Fibula {
    namespace Graphics {
        class WindowAdapterInterface
        {
        protected:
            const std::string title = "[Fibula Engine :: v1.0.0]";
            const int width = 640;
            const int height = 480;

            EventDispatcher::Dispatcher &dispatcher;
            Core::Kernel *kernel;

        public:
            WindowAdapterInterface(
                    const std::string &title,
                    const int width,
                    const int height,
                    EventDispatcher::Dispatcher &dispatcher,
                    Core::Kernel *kernel
            ) : title(title), width(width), height(height), dispatcher(dispatcher), kernel(kernel)
            { }

            virtual void handleEvents() = 0;

            virtual std::string getName() = 0;

            virtual ~WindowAdapterInterface()
            { }
        };
    }
}

#endif //FIBULA_WINDOWADAPTERINTERFACE_HPP
