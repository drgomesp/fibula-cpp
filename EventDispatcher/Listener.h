#pragma once

#include "Event.h"
#include <iostream>

namespace Fibula {
    namespace EventDispatcher {
        template<template<class> class EventType, class PayloadType>
        class Listener {
        public:
            virtual void handleEvent(const EventType<PayloadType> &event) = 0;
        };
    }
}
