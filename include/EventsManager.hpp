#ifndef EVENTS_MANAGER_H
#define EVENTS_MANAGER_H

#include <vector>
#include "EventEnums.hpp"

class GameEntity;
class Observer;

class EventsManager
{
    private:
        static std::vector<std::vector<Observer*>> subscribers;
    public:
        static void init();
        static void Subscribe(Event event, Observer* observer);

        static void Notify(Event event);
        static void Notify(Event event, GameEntity* entity);
};

#endif