//
// Created by Vinícius Ferreira Aguiar on 09/01/23.
//

#ifndef GAME_PLAYERINPUTSYSTEM_H
# define GAME_PLAYERINPUTSYSTEM_H

# define GL_SILENCE_DEPRECATION

//# include <GL/glew.h>
# include  <GLFW/glfw3.h>

# include "GAME/Entity.h"
# include "GAME/Vector2.h"
# include "GAME/Scene.h"



class PlayerInputSystem
{
private:

    GLFWwindow *_window;
    Entity     *_current_player;
    Vector2     _last_mouse_position;
    Vector3     _eye_vector;
    int         _items_collected;
    int         _total_items;

    void keyCallback(GLFWwindow *window,
                     int key,
                     int scancode,
                     int action,
                     int mods);
    bool checkCollisions(std::vector<Entity *> *entity_array, Vector3 camera_position);

    explicit PlayerInputSystem(int total_items);
    ~PlayerInputSystem();

public:

    void setCurrentPlayer(Entity *player);
    void update(std::vector<Entity *> *entity_array);
    int  getItemsCollected();

    static void               keyCallbackFun(GLFWwindow *window,
                                             int key,
                                             int scancode,
                                             int action,
                                             int mods);
    static PlayerInputSystem &getPlayerInputSystem(int total_items);
    static void               destroyPlayerInputSystem();

};



#endif //GAME_PLAYERINPUTSYSTEM_H
