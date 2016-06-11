#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include <Fibula/Events/Payload.hpp>

namespace Fibula {
    namespace Bridge {

        using Payload = Fibula::Events::Payload;

        class SFMLPayload : public Payload
        {
            const sf::Event &originalEvent;
        public:
            SFMLPayload(const sf::Event &originalEvent) : originalEvent(originalEvent)
            { }

            const sf::Event &getOriginalEvent() const
            {
                return originalEvent;
            }

            virtual ~SFMLPayload()
            { }
        };
    }
}
