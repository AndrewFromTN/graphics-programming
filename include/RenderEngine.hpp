#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

#include <vector>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Observer.hpp"
#include "SIMD.hpp"

struct GLFWwindow;
class GameEntity;
class Shader;
class SceneManager;

class RenderEngine : public Observer
{
    private:
        // Not technically a queue
        std::map<std::string, std::vector<GameEntity*>> render_queue;
        std::map<std::string, Shader*> shaders;

        GLFWwindow* window;

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

        glm::mat4 projection_matrix;

        SIMD::sse_mat4 tmp_matrix_4f;

        bool ortho_projection;

        static float screen_width;
        static float screen_height;

        SceneManager* scene_manager;
    public:
        RenderEngine();
        ~RenderEngine();

        GLFWwindow* get_window();
        void shutdown();
        void clear_queue();
        void render();

        virtual void onNotify(Event event, GameEntity* entity) override;

        void swap_projection();

        void set_scene_manager(SceneManager* scene_manager);
};

#endif