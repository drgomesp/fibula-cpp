#ifndef FIBULA_WINDOWADAPTERINTERFACE_HPP
#define FIBULA_WINDOWADAPTERINTERFACE_HPP

#include <string>
#include <Fibula/EventDispatcher/Dispatcher.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Adapter {
            class WindowAdapterInterface
            {
            public:
                const std::string title = "[Fibula Engine :: v1.0.0]";
                const int width = 640;
                const int height = 480;
                Fibula::EventDispatcher::Dispatcher &dispatcher;

                WindowAdapterInterface(const std::string &title, const int width, const int height,
                                       EventDispatcher::Dispatcher &dispatcher)
                        : title(title),
                          width(width),
                          height(height),
                          dispatcher(dispatcher) { }

                virtual void create(
                        const std::string &title,
                        const int width,
                        const int height,
                        EventDispatcher::Dispatcher &dispatcher
                ) = 0;

                virtual void handleEvents() = 0;
                virtual std::string getName() = 0;

                virtual ~WindowAdapterInterface()
                { }
            };
        }
    }
}

#endif //FIBULA_WINDOWADAPTERINTERFACE_HPP
