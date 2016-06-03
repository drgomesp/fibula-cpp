#include <memory>

#include <demo-game/Core/Kernel.hpp>
#include <demo-game/Listeners/SDL/MousePositionListener.hpp>

#include <Fibula/EventDispatcher/Dispatcher.hpp>

using namespace std;
using namespace Fibula::EventDispatcher;
using namespace Game::Core;
using namespace Game::Listeners::SDL;

Kernel::Kernel(const std::string &name) : name(name)
{
    this->dispatcher = make_shared<Dispatcher>();

    std::shared_ptr<MousePositionListener> mousePositionListener = std::make_shared<MousePositionListener>(this);
    this->addListener("event.sdl", mousePositionListener);
}
