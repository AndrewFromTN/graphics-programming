#include "Camera.hpp"
#include <glm/gtx/matrix_decompose.hpp>

Camera::Camera(const glm::vec3& initial_position)
{
    position = initial_position;
    orientation = glm::quat(glm::vec3(0.0f, 0.0f, 0.0f));
}

Camera::~Camera()
{

}

void Camera::move(const glm::vec3& distance)
{
    position += distance * orientation;
}

void Camera::move(float x, float y, float z)
{
    position += glm::vec3(x, y, z) * orientation;
}

void Camera::move_to_point(const glm::vec3& target)
{
    //LERP
}

void Camera::move_to_point(float x, float y, float z)
{
    //LERP
}

void Camera::rotate(float angle, const glm::vec3& axis)
{
    orientation *= glm::angleAxis(angle, axis * orientation);
}

void Camera::rotate(float angle, float x, float y, float z)
{
    orientation *= glm::angleAxis(angle, glm::vec3(x, y, z) * orientation);
}

void Camera::rotate_around_point(float angle, const glm::vec3& target)
{
    glm::mat4 _view = glm::lookAt(position, target, glm::vec3(0.0f, 1.0f, 0.0f));

    glm::quat _orientation;
    glm::vec3 scale;
    glm::vec3 translation;
    glm::vec3 skew;
    glm::vec4 perspective;
    glm::decompose(_view, scale, _orientation, translation, skew, perspective);

    orientation = glm::conjugate(_orientation);
}

void Camera::rotate_around_point(float angle, float x, float y, float z)
{

}

void Camera::zoom(const glm::vec3& distance)
{

}

void Camera::zoom(float x, float y, float z)
{

}

void Camera::zoom_to_point(const glm::vec3& target)
{
    //LERP
}

void Camera::zoom_to_point(float x, float y, float z)
{
    //LERP
}

glm::mat4 Camera::get_view() const
{
    return glm::translate(glm::mat4_cast(orientation), position);
}

glm::vec3 Camera::get_position() const
{
    return position;
}
