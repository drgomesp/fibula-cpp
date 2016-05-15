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
    virtual const void handleEvent(EventType<PayloadType> *event) override {
        cout << "SimpleListener::handleEvent" << endl;
    }

    ~SimpleListener() {}
};

int main() {
    Payload *simplePayload = new SimplePayload(25);
    Event<Payload> *simpleEvent = new SimpleEvent<Payload>(*simplePayload);

    Listener<Event, Payload> *simpleListener = new SimpleListener<Event, Payload>();

    Dispatcher *dispatcher = new Dispatcher();

    dispatcher->addListener(simpleListener);
    dispatcher->dispatchEvent(simpleEvent);

    return EXIT_SUCCESS;
}
