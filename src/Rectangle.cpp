#include "Rectangle.hpp"

FloatRect::FloatRect(const glm::vec3& position, float width, float height)
{
    this->position = position;
    this->width = width;
    this->height = height;
}

bool FloatRect::contains(const glm::vec3& point) const
{
    return (point.x >= position.x && point.x <= position.x + width) &&
           (point.y >= position.y && point.y <= position.y + height);
}

bool FloatRect::intersects(const FloatRect& intersection) const
{
    return (position.x < intersection.position.x + intersection.width && 
            position.x + width > intersection.position.x &&
            position.y < intersection.position.y + intersection.height &&
            position.y + height > intersection.position.y);
}
