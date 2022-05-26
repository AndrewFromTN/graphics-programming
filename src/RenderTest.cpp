#include <iostream>
#include <chrono>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "LoggingService.hpp"
#include "RenderEngine.hpp"
#include "SceneManager.hpp"
#include "EventsManager.hpp"
#include "ConfigLoader.hpp"
#include "Camera.hpp"

bool press = false;

void processInput(GLFWwindow* window, RenderEngine* render_engine)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        press = true; 
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_RELEASE) {
        if (press)
            render_engine->swap_projection();

        press = false;
    }
}

int main(int argc, char** argv)
{
    std::remove("./DebugLog.txt");

    //LoggingService<FileLogger> logging_service;

    ConfigLoader::LoadConfigFile("./engine.conf");

    EventsManager::init();

    RenderEngine render_engine;
    SceneManager scene_manager;

    render_engine.set_scene_manager(&scene_manager);

    using clock = std::chrono::high_resolution_clock;

    const int MS_PER_UPDATE = 16;

    std::chrono::milliseconds lag(0);
    clock::time_point previous = clock::now();
    clock::time_point current;

    //ToDo(andrew): This loop needs a timestep fix
    GLFWwindow* window = render_engine.get_window();
    while(!glfwWindowShouldClose(window))
    {
        current = clock::now();
        auto elapsed = current - previous;
        previous = current;
        lag += std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);

        processInput(window, &render_engine);

        while (lag >= std::chrono::milliseconds(MS_PER_UPDATE))
        {
            scene_manager.update();
            scene_manager.add_to_render_queue();
            lag -= std::chrono::milliseconds(MS_PER_UPDATE);
        }

        render_engine.render();

        // Seems inefficient; I'd rather have
        // the scene manager responsible for
        // removing things that don't need to be drawn
        render_engine.clear_queue();

        glfwPollEvents();    
    }

    render_engine.shutdown();

	return 0;
}
