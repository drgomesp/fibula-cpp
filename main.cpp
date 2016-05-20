#include <iostream>

#include "EventDispatcher/Event.h"
#include "EventDispatcher/Listener.h"
#include "EventDispatcher/Dispatcher.h"

using namespace std;
using namespace Fibula::EventDispatcher;

class SimplePayload : public Payload {
protected:
    int number;
public:
    SimplePayload(int number) : number(number) { }
    int getNumber() { return number; };
};

class SimpleEvent : public Event {
public:
    SimpleEvent(SimplePayload &payload) : Event(payload) { }
};

class ComplexEvent : public Event {
public:
    ComplexEvent(SimplePayload &payload) : Event(payload) { }
};

class SimpleListener : public Listener {
public:
    virtual const void handleEvent(Event *event) override {
        SimpleEvent *e = dynamic_cast<SimpleEvent *>(event);

        if (e) {
            cout << "SimpleListener::handleEvent" << endl;
        }
    }
};

class ComplexListener : public Listener {
public:
    virtual const void handleEvent(Event *event) override {
        ComplexEvent *e = dynamic_cast<ComplexEvent *>(event);

        if (e) {
            cout << "ComplexListener::handleEvent" << endl;
        }
    }
};

int main() {
    boost::shared_ptr<SimplePayload> simplePayload(new SimplePayload(25));
    boost::shared_ptr<Event> simpleEvent(new SimpleEvent(*boost::get_pointer(simplePayload)));

    boost::shared_ptr<SimpleListener> simpleListener(new SimpleListener());
    boost::shared_ptr<ComplexListener> complexListener(new ComplexListener());
    boost::shared_ptr<Dispatcher> dispatcher(new Dispatcher());

    dispatcher->addListener(boost::get_pointer(simpleListener));
    dispatcher->addListener(boost::get_pointer(complexListener));
    
    dispatcher->dispatchEvent(boost::get_pointer(simpleEvent));

    return EXIT_SUCCESS;
}
