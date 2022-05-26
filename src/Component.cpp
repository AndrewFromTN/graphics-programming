#include "Component.hpp"
#include "EventsManager.hpp"

RenderComponent::RenderComponent(const std::string& shader, float* render_coords) : shader(shader), render_coords(render_coords)
{
    type = "Render";
}

void RenderComponent::execute(GameEntity* e)
{
    EventsManager::Notify(Event::RENDER_MODEL, e);
}