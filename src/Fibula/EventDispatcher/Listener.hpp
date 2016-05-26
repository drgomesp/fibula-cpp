#ifndef FIBULA_LISTENER_HPP
#define FIBULA_LISTENER_HPP

enum LISTENER_RESPONSE
{
    SUCCESS = 0, FAILURE = 1
};

namespace Fibula {
    namespace EventDispatcher {
        class Listener
        {
        public:
            virtual LISTENER_RESPONSE handleEvent(Event *event) = 0;

            virtual ~Listener()
            { }
        };
    }
}

#endif //FIBULA_LISTENER_HPP
