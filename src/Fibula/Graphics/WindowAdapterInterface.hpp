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
            std::string name;
            const std::string title = "[Fibula Engine :: v1.0.0]";
            const unsigned int width = 640;
            const unsigned int height = 480;

            EventDispatcher::Dispatcher &dispatcher;
            Core::Kernel *kernel;

        public:
            WindowAdapterInterface(
                    std::string name,
                    const std::string &title,
                    const unsigned int width,
                    const unsigned int height,
                    EventDispatcher::Dispatcher &dispatcher,
                    Core::Kernel *kernel
            ) : name(name), title(title), width(width), height(height), dispatcher(dispatcher), kernel(kernel)
            { }

            virtual void handleEvents() = 0;

            inline std::string getName()
            {
                return this->name;
            }

            virtual ~WindowAdapterInterface()
            { }
        };
    }
}

#endif //FIBULA_WINDOWADAPTERINTERFACE_HPP
