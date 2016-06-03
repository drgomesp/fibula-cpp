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
#include <SFML/Graphics/Drawable.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Window {

            using namespace std;
            using Kernel = Fibula::Core::Kernel;
            using Dispatcher = Fibula::EventDispatcher::Dispatcher;
            using RendererAdapter = Fibula::Graphics::Window::RendererAdapter;

            class WindowAdapter
            {
            protected:
                string name;
                const std::string title = "[Fibula Engine :: v1.0.0]";
                const unsigned int width = 640;
                const unsigned int height = 480;

                shared_ptr<Dispatcher> dispatcher;
                Kernel &kernel;
                shared_ptr<RendererAdapter> renderer;

            public:
                WindowAdapter(
                    const string &name,
                    const string &title,
                    const unsigned int width,
                    const unsigned int height,
                    shared_ptr<Dispatcher> dispatcher,
                    Kernel &kernel,
                    shared_ptr<RendererAdapter> renderer)
                    : name(name),
                      title(title),
                      width(width),
                      height(height),
                      dispatcher(dispatcher),
                      kernel(kernel),
                      renderer(renderer)
                { }

                virtual void handleEvents() = 0;

                virtual void render() = 0;

                inline unsigned int getWidth()
                {
                    return width;
                }

                inline unsigned int getHeight()
                {
                    return height;
                }

                inline std::string getName()
                {
                    return this->name;
                }

                virtual ~WindowAdapter()
                { }
            };
        }
    }
}

#endif //FIBULA_WINDOWADAPTERINTERFACE_HPP
