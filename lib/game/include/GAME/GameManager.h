//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#ifndef GAME_GAMEMANAGER_H
# define GAME_GAMEMANAGER_H

# define GL_SILENCE_DEPRECATION
# define UPDATES_PER_SECOND 60.0f

//# include <GL/glew.h>
# include <GLFW/glfw3.h>

# include "DEBUG/glfw_error.h"
# include "GAME/CameraSystem.h"
# include "GAME/Entity.h"
# include "GAME/MovementSystem.h"
# include "GAME/PlayerInputSystem.h"
# include "GAME/RenderSystem.h"
# include "GAME/ResourceManager.h"
# include "GAME/Scene.h"

# include <iostream>



class GameManager
{
private:

    bool               _running;
    GLFWwindow        *_window;
    RenderSystem      *_render_system;
    ResourceManager   *_resource_manager;
    Entity            *_entity;
    MovementSystem    *_movement_system;
    CameraSystem      *_camera_system;
    PlayerInputSystem *_player_input_system;
    Scene             *_scene;

    explicit GameManager(const char *map);
    ~GameManager();

public:

    void runGameLoop();

    static GameManager &getGameManager(const char *map);
    static void         destroyGameManager();

};



#endif //GAME_GAMEMANAGER_H
