#include <Fibula/Bridge/SFMLEventListener.hpp>

#include <Fibula/Bridge/SFMLEvent.hpp>

using namespace std;
using namespace Fibula::Bridge;
using namespace Fibula::Events;

LISTENER_RESPONSE SFMLEventListener::handleEvent(shared_ptr<const Event> event) const
{
    const SFMLEvent *_sfml_event = dynamic_cast<const SFMLEvent *>(event.get());

    if (!_sfml_event) {
        return LISTENER_RESPONSE::FAILURE;
    }

    auto e = _sfml_event->getPayload().getOriginalEvent();

    switch (e.type) {
        case (sf::Event::Closed):
            this->kernel->terminate();
            return LISTENER_RESPONSE::SUCCESS;
        case (sf::Event::KeyReleased):
            if (e.key.code == sf::Keyboard::Escape) {
                this->kernel->terminate();
                return LISTENER_RESPONSE::SUCCESS;
            }
        default:
            return LISTENER_RESPONSE::FAILURE;
    }
}
