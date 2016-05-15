#pragma once

#include "Event.h"
#include <iostream>

namespace Fibula {
    namespace EventDispatcher {
        template<template<class> class EventType, class PayloadType>
        class Listener {
        public:
            virtual const void handleEvent(EventType<PayloadType> *event) = 0;
            virtual ~Listener() {};
        };
    }
}
