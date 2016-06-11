#pragma once

#include <map>
#include <string>
#include <vector>

namespace Fibula {
    namespace Events {
        class Listener;

        using namespace std;

        using ListenerVector = vector<shared_ptr<Listener>>;
        using ListenerMap = map<string, ListenerVector>;
    }
}

#include <Fibula/Events/Event.hpp>
#include <Fibula/Events/Listener.hpp>
#include <Fibula/Events/Payload.hpp>

namespace Fibula {
    namespace Events {

        using namespace std;

        class Dispatcher
        {
        private:
            ListenerMap listeners;
        public:
            void addListener(const string &eventName, shared_ptr<Listener> listener);
            void dispatchEvent(const string &eventName, shared_ptr<const Event> event) const;

            ~Dispatcher()
            { }

        private:
            ListenerMap::const_iterator searchListenersByPrefix(const string &prefix) const;
        };
    }
}
