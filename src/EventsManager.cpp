#include "EventsManager.hpp"
#include <algorithm>
#include <iostream>
#include "Observer.hpp"

std::vector<std::vector<Observer*>> EventsManager::subscribers = std::vector<std::vector<Observer*>>();

void EventsManager::init()
{
    std::vector<Observer*> render_models;
    subscribers.push_back(render_models);
}

void EventsManager::Subscribe(Event event, Observer* observer)
{
    subscribers[event].push_back(observer);
}

void EventsManager::Notify(Event event)
{

}

void EventsManager::Notify(Event event, GameEntity* entity)
{
    std::for_each(subscribers[event].begin(), subscribers[event].end(), [&](Observer* obs)
    {
        obs->onNotify(event, entity);
    });
}