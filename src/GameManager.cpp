//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#include "GAME/GameManager.h"



GameManager::GameManager(const char *map)
    : _running(true)
    , _window(glfwGetCurrentContext())
    , _render_system(&RenderSystem::getRenderSystem())
    , _resource_manager(&ResourceManager::getResourceManager())
    , _movement_system(&MovementSystem::getMovementSystem())
    , _camera_system(&CameraSystem::getCameraSystem())
    , _scene(new Scene(map))
{
    _player_input_system = &PlayerInputSystem::getPlayerInputSystem(_scene->getCollectibles());
}



GameManager::~GameManager()
{
    ResourceManager::destroyResourceManager();
    CameraSystem::destroyCameraSystem();
    RenderSystem::destroyRenderSystem();
    PlayerInputSystem::destroyPlayerInputSystem();
}



void
GameManager::runGameLoop()
{
    double last_time = glfwGetTime();
    double delta_time = 0.0F;

    while (_running) {
        double current_Time = glfwGetTime();

        delta_time += (current_Time - last_time) * UPDATES_PER_SECOND;
        last_time = current_Time;

        while (delta_time >= 1.0F) {
            _running = glfwWindowShouldClose(_window) == GLFW_FALSE;

            _movement_system->update(_scene->getChildren());
            _player_input_system->update(_scene->getChildren());

            --delta_time;
        }

        _render_system->render(_scene->getChildren());

        _render_system->renderHUD(_scene->getCollectibles(),
                                  _player_input_system->getItemsCollected());

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}



GameManager &
GameManager::getGameManager(const char *map)
{
    static GameManager *game_manager = nullptr;

    if (game_manager == nullptr) {
        GLFW_SETUP();

        if (glfwInit() == GLFW_FALSE) {
            return *game_manager;
        }

        glfwWindowHint(GLFW_DEPTH_BITS, 24);
        glfwWindowHint(GLFW_RED_BITS  , 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS , 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 8);
        glfwWindowHint(GLFW_SAMPLES   , 16);
        glfwWindowHint(GLFW_RESIZABLE , GL_FALSE);

        const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        GLFWwindow *window = glfwCreateWindow(mode->width, mode->height, "Simple Game", glfwGetPrimaryMonitor(), nullptr);
        if (window == nullptr)
        {
            glfwTerminate();
            return *game_manager;
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        game_manager = new GameManager(map);

        std::cout << "GameManager created!" << std::endl;
    }

    return *game_manager;
}



void
GameManager::destroyGameManager()
{
    GameManager *game_manager = &getGameManager(nullptr);

    if (game_manager != nullptr) {
        delete game_manager;

        glfwDestroyWindow(glfwGetCurrentContext());
        glfwTerminate();

        std::cout << "GameManager destroyed!" << std::endl;
    }
}
