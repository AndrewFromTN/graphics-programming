#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
    private:
        glm::vec3 position;

        glm::quat orientation;
    public:
        Camera(const glm::vec3& initial_position);
        ~Camera();

        void move(const glm::vec3& distance);
        void move(float x, float y, float z);
        void move_to_point(const glm::vec3& target);
        void move_to_point(float x, float y, float z);
        void rotate(float angle, const glm::vec3& axis);
        void rotate(float angle, float x, float y, float z);
        void rotate_around_point(float angle, const glm::vec3& target);
        void rotate_around_point(float angle, float x, float y, float z);
        void zoom(const glm::vec3& distance);
        void zoom(float x, float y, float z);
        void zoom_to_point(const glm::vec3& target);
        void zoom_to_point(float x, float y, float z);

        glm::mat4 get_view() const;
        glm::vec3 get_position() const;
};

#endif
