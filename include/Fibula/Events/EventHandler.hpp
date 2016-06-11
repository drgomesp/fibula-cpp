#pragma once

namespace Fibula {
    namespace Events {
        class EventHandler {
        public:
            virtual void handleEvents() = 0;
        };
    }
}