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

template<class PayloadType>
class SimpleEvent : public Event<PayloadType> {
protected:
    PayloadType payload;
public:
    SimpleEvent(PayloadType &payload) : Event<PayloadType>(payload), payload(payload) { }
};

template<template<class> class EventType, class PayloadType>
class SimpleListener : public Listener<EventType, PayloadType> {
public:
    virtual void handleEvent(const EventType<PayloadType> &event) override {
        cout << "SimpleListener::handleEvent" << endl;
    }
};

int main() {
    SimplePayload *simplePayload = new SimplePayload(25);
    SimpleEvent<SimplePayload> *simpleEvent = new SimpleEvent<SimplePayload>(*simplePayload);

    SimpleListener<SimpleEvent, SimplePayload> *simpleListener = new SimpleListener<SimpleEvent, SimplePayload>();

    Dispatcher *dispatcher = new Dispatcher({});
    Listener<Event, Payload> *cSimpleListener = dynamic_cast<Listener<Event, Payload> *>(simpleListener);
    dispatcher->addListener(cSimpleListener);

    Event<Payload> *cSimpleEvent = dynamic_cast<Event<Payload> *>(simpleEvent);
    dispatcher->dispatchEvent(*cSimpleEvent);

    return EXIT_SUCCESS;
}
