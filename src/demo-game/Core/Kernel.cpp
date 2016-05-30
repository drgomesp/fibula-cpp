#include <memory>

#include <demo-game/Core/Kernel.hpp>
#include <demo-game/Listeners/SDL/MousePositionListener.hpp>

using namespace Game::Core;
using namespace Game::Listeners::SDL;

Kernel::Kernel(const std::string &graphicsAdapter) : Fibula::Core::Kernel(graphicsAdapter)
{

}
