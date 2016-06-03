#ifndef FIBULA_SFMLWINDOWADAPTER_HPP
#define FIBULA_SFMLWINDOWADAPTER_HPP

#include <SFML/Graphics.hpp>
#include <Fibula/Graphics/Window/WindowAdapter.hpp>

namespace Fibula {
    namespace Graphics {
        namespace Window {
            namespace Adapter {
                using namespace std;
                using WindowAdapter = Fibula::Graphics::Window::WindowAdapter;

                class SFMLWindowAdapter : public WindowAdapter
                {
                protected:
                    shared_ptr<sf::RenderWindow> window;

                public:
                    SFMLWindowAdapter(
                        const string &title,
                        const unsigned int width,
                        const unsigned int height,
                        shared_ptr<Dispatcher> dispatcher,
                        Kernel &kernel,
                        shared_ptr<RendererAdapter> renderer);

                    virtual void handleEvents() override;

                    virtual void render() override;

                    inline sf::RenderWindow *getWindowImpl()
                    {
                        return this->window.get();
                    }

                    ~SFMLWindowAdapter();
                };
            }
        }

    };
}


#endif //FIBULA_SFMLWINDOWADAPTER_HPP
