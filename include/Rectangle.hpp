#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <glm/glm.hpp>

class FloatRect
{
    public:
        FloatRect(const glm::vec3& position, float width, float height);
        FloatRect(const FloatRect& rect) = default;

        glm::vec3 position;
        float width, height;

        bool contains(const glm::vec3& point) const;
        bool intersects(const FloatRect& intersection) const;
};

#endif