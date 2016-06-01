#ifndef FIBULA_WINDOWADAPTERINTERFACE_HPP
#define FIBULA_WINDOWADAPTERINTERFACE_HPP

#include <string>
#include <boost/shared_ptr.hpp>

#include <Fibula/Graphics/Window/RendererAdapter.hpp>

namespace Fibula {
    namespace Core {
        class Kernel;
    }
}

#include <Fibula/Core/Kernel.hpp>
#include <Fibula/EventDispatcher/Dispatcher.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Window {

            using RendererAdapter = Fibula::Graphics::Window::RendererAdapter;

            class WindowAdapterInterface
            {
            protected:
                std::string name;
                const std::string title = "[Fibula Engine :: v1.0.0]";
                const unsigned int width = 640;
                const unsigned int height = 480;

                EventDispatcher::Dispatcher &dispatcher;
                Core::Kernel &kernel;
                std::shared_ptr<RendererAdapter> rendererAdapter;

            public:
                WindowAdapterInterface(
                    std::string name,
                    const std::string &title,
                    const unsigned int width,
                    const unsigned int height,
                    EventDispatcher::Dispatcher &dispatcher,
                    Core::Kernel &kernel
                ) :
                    name(name),
                    title(title),
                    width(width),
                    height(height),
                    dispatcher(dispatcher),
                    kernel(kernel)
                { }

                virtual void handleEvents() = 0;
                virtual void render() = 0;

                inline const unsigned int getWidth() const
                {
                    return width;
                }

                inline const unsigned int getHeight() const
                {
                    return height;
                }

                inline std::string getName()
                {
                    return this->name;
                }

                virtual ~WindowAdapterInterface()
                { }
            };
        }
    }
}

#endif //FIBULA_WINDOWADAPTERINTERFACE_HPP
