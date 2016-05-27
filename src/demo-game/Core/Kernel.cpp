#include <memory>

#include <demo-game/Core/Kernel.hpp>
#include <demo-game/Listeners/SDL/MousePositionListener.hpp>

using namespace Game::Core;
using namespace Game::Listeners::SDL;

Kernel::Kernel(const std::string &graphicsAdapter) : Fibula::Core::Kernel(graphicsAdapter)
{
    std::shared_ptr<MousePositionListener> mousePositionListener = std::make_shared<MousePositionListener>(this);
    this->addListener("event.sdl", mousePositionListener);
}
