#include "RenderEngine.hpp"
#include <iostream>
#include <cassert>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "LoggingService.hpp"
#include "EventsManager.hpp"
#include "GameEntity.hpp"
#include "Shader.hpp"
#include "Component.hpp"
#include "ConfigLoader.hpp"
#include "SceneManager.hpp"

float RenderEngine::screen_width = 800.0f;
float RenderEngine::screen_height = 800.0f;

void RenderEngine::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);

    //screen_width = width;
    //screen_height = height;
}

void RenderEngine::swap_projection()
{
    ortho_projection = !ortho_projection;

    projection_matrix = ortho_projection ? glm::ortho(0.0f, screen_width, screen_height, 0.0f, -1.0f, 320.0f)
                                         : glm::perspective(glm::radians(45.0f), screen_width / screen_height, 0.1f, 100.0f);
}

RenderEngine::RenderEngine()
{
    LoggingService<FileLogger> logging_service;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(screen_width, screen_height, "RenderTest", NULL, NULL);
    if (window == nullptr)
    {
        logging_service.log(LoggingLevel::CATASTROPHIC_FAILURE, "Failed to create the window.\n");
        glfwTerminate();
        exit(-1);
    }

    this->window = window;

    glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 

    projection_matrix = glm::perspective(glm::radians(45.0f), screen_width / screen_height, 0.1f, 100.0f);
    #if VERBOSE_LOGGING
        logging_service.log(LoggingLevel::SUCCESS, "Created perspective projection.\n");
    #endif

    ortho_projection = false;

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
        logging_service.log(LoggingLevel::CATASTROPHIC_FAILURE, "Failed to initialize GLAD.\n");
        glfwTerminate();
		exit(-1);
	}

    glEnable(GL_DEPTH_TEST);

    #if VERBOSE_LOGGING
        logging_service.log(LoggingLevel::SUCCESS, "Initialized Render Engine.\n");
    #endif

    EventsManager::Subscribe(Event::RENDER_MODEL, this);

    shaders["tile_shader"] = new Shader((ConfigLoader::args.at("SHADER_DIR") + "3.3.shader.vs").c_str(),
                                        (ConfigLoader::args.at("SHADER_DIR") + "3.3.shader.fs").c_str());

    #if WIREFRAME
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    #endif
}

void RenderEngine::onNotify(Event event, GameEntity* entity)
{
    if (event == Event::RENDER_MODEL)
    {
        render_queue[entity->getShader()].push_back(entity);
    }
}

void RenderEngine::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 view = scene_manager->get_view();
    glm::mat4 model(1.0f);

    for (auto& shader_type : render_queue)
    {
        #if SLOW_CODE
            assert(shaders.at(shader_type.first) != nullptr);
        #endif

        shaders.at(shader_type.first)->use();
        shaders.at(shader_type.first)->setInt("ourTexture", 0);
        
        std::for_each(shader_type.second.begin(), shader_type.second.end(), [&](GameEntity* e)
        {
            model = e->getModelMatrix();
            //model = glm::translate(model, glm::vec3(-0.5f, 0.5f, 0.0f));
            //model = glm::scale(model, glm::vec3(1 / screen_width, -1 / screen_height, 0.0f));

            shaders.at(shader_type.first)->setVec3("color", glm::vec3(1, 1, 1));
            shaders.at(shader_type.first)->setMat4("projection", projection_matrix);
            shaders.at(shader_type.first)->setMat4("view", view);

            const float* tmp = (const float*)glm::value_ptr(view);
            SIMD::sse_mat4 tmp_view;
            for (int i = 0; i < 16; ++i)
            {
                tmp_view.data[i] = tmp[i];
            }

            tmp = (const float*)glm::value_ptr(model);
            SIMD::sse_mat4 tmp_model;
            for (int i = 0; i < 16; ++i)
            {
                tmp_model.data[i] = tmp[i];
            }

            SIMD::mmul_vec4(tmp_view.data, tmp_model.data, tmp_matrix_4f.data);
            shaders.at(shader_type.first)->setMat4("mv", glm::make_mat4(tmp_matrix_4f.data));
/*
float test[2] = {0, 0};
float test2[2] = {0, 32.f/512.f};
float test3[2] = {32.f/512.f, 0};
float test4[2] = {32.f/512.f, 32.f/512.f};
glBindBuffer(GL_ARRAY_BUFFER, e->getVBO());
glBufferSubData(GL_ARRAY_BUFFER, 12, 8, (void*)test);
glBufferSubData(GL_ARRAY_BUFFER, 32, 8, (void*)test2);
glBufferSubData(GL_ARRAY_BUFFER, 52, 8, (void*)test3);
glBufferSubData(GL_ARRAY_BUFFER, 72, 8, (void*)test4);
*/
            glBindTexture(GL_TEXTURE_2D, e->getTexture());
            glBindVertexArray(e->getVAO());
            glDrawElements(GL_TRIANGLES, e->getVertexSize(), GL_UNSIGNED_INT, 0);
        });
    }

    glfwSwapBuffers(window);
}

void RenderEngine::clear_queue()
{
    render_queue.clear();
}

GLFWwindow* RenderEngine::get_window()
{
    return window;
}

void RenderEngine::set_scene_manager(SceneManager* scene_manager)
{
    this->scene_manager = scene_manager;
}

void RenderEngine::shutdown()
{
    for (auto& kv : shaders)
    {
        delete kv.second;
        kv.second = nullptr;
    }

    glfwTerminate();
}

RenderEngine::~RenderEngine()
{

}