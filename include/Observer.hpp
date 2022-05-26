#ifndef OBSERVER_H
#define OBSERVER_H

#include "EventEnums.hpp"

class GameEntity;

class Observer
{
    public:
        virtual ~Observer() {}
        virtual void onNotify(Event event, GameEntity* entity) = 0;
};

#endif