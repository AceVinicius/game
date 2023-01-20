//
// Created by Vinícius Ferreira Aguiar on 09/01/23.
//

#include "GAME/PlayerInputSystem.h"



PlayerInputSystem::PlayerInputSystem(int total_items)
    : _window(glfwGetCurrentContext())
    , _items_collected(0)
    , _total_items(total_items)
{
    glfwGetCursorPos(_window, &_last_mouse_position.x, &_last_mouse_position.y);
}



PlayerInputSystem::~PlayerInputSystem()
{

}



void
PlayerInputSystem::keyCallback(GLFWwindow *window,
                               int key,
                               int scancode,
                               int action,
                               int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        if (GLFW_CURSOR_DISABLED == glfwGetInputMode(glfwGetCurrentContext(), GLFW_CURSOR)) {
            glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        } else {
            glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        }
    }
}



void
PlayerInputSystem::setCurrentPlayer(Entity *player)
{
    _current_player = player;
    _eye_vector = normalizeVector3(player->getEyeVector());
}



void
PlayerInputSystem::update(std::vector<Entity *> *entity_array)
{
    if (_current_player != nullptr && glfwGetInputMode(_window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED) {

        if (glfwGetKey(_window, GLFW_KEY_W)) {
            Vector3 vector = addVector3(_current_player->getPosition(),
                                        scalerMultiplyVector3(_eye_vector, 0.05F));

            if (!checkCollisions(entity_array, vector)) {
                _current_player->setPosition(vector);
            }
        }

        if (glfwGetKey(_window, GLFW_KEY_S)) {
            Vector3 vector = subtractVector3(_current_player->getPosition(),
                                             scalerMultiplyVector3(_eye_vector, 0.05F));

            if (!checkCollisions(entity_array, vector)) {
                _current_player->setPosition(vector);
            }
        }

        if (glfwGetKey(_window, GLFW_KEY_A)) {
            Vector3 vector = subtractVector3(_current_player->getPosition(),
                                             scalerMultiplyVector3(crossProductVector3(_eye_vector,makeVector3(0.0F, 1.0F, 0.0F)),0.05F));

            if (!checkCollisions(entity_array, vector)) {
                _current_player->setPosition(vector);
            }
        }

        if (glfwGetKey(_window, GLFW_KEY_D)) {
            Vector3 vector = addVector3(_current_player->getPosition(),
                                        scalerMultiplyVector3(crossProductVector3(_eye_vector, makeVector3(0.0F, 1.0F, 0.0F)), 0.05F));

            if (!checkCollisions(entity_array, vector)) {
                _current_player->setPosition(vector);
            }
        }

        Vector2 current_mouse_position;
        glfwGetCursorPos(_window, &current_mouse_position.x, &current_mouse_position.y);

        _eye_vector = transformVector3(_eye_vector,makeRotationMatrix3((3.14F / (4.0F * 160.0F)) * -(current_mouse_position.x - _last_mouse_position.x), 0.0F, 1.0F, 0.0F));

        glfwGetCursorPos(_window, &_last_mouse_position.x, &_last_mouse_position.y);

        _current_player->setEyeVector(addVector3(_current_player->getPosition(), _eye_vector));
    }
}



bool
PlayerInputSystem::checkCollisions(std::vector<Entity *> *entity_array, Vector3 camera_position)
{
    bool collision_x = false;
    bool collision_y = false;
    bool collision_z = false;

    for (auto entity : *entity_array) {
        if (entity->getVertexBuffer() != nullptr) {
            collision_x = entity->getPosition().x + 0.5F >= camera_position.x - 0.1F && camera_position.x + 0.1F >= entity->getPosition().x - 0.5F;
            collision_y = entity->getPosition().y + 0.5F >= camera_position.y - 0.1F && camera_position.y + 0.1F >= entity->getPosition().y - 0.5F;
            collision_z = entity->getPosition().z + 0.5F >= camera_position.z - 0.1F && camera_position.z + 0.1F >= entity->getPosition().z - 0.5F;

            if (collision_x && collision_y && collision_z) {

                switch (entity->getType()) {
                    case WALL: {
                        return true;
                    }

                    case ELEVATOR_UP: {
                        Vector3 vector = _current_player->getPosition();
                        vector.x = entity->getPosition().x;
                        vector.y += 2.0F;
                        vector.z = entity->getPosition().z;

                        _current_player->setPosition(vector);
                        return true;
                    }

                    case ELEVATOR_DOWN: {
                        Vector3 vector = _current_player->getPosition();

                        vector.x = entity->getPosition().x;
                        vector.y -= 2.0F;
                        vector.z = entity->getPosition().z;

                        _current_player->setPosition(vector);
                        return true;
                    }

                    case COLLECTIBLE: {
                        (void) std::remove(entity_array->begin(), entity_array->end(), entity);
                        ++_items_collected;
                        return true;
                    }

                    case START: {
                        if (_items_collected == _total_items) {
                            glfwSetWindowShouldClose(_window, GLFW_TRUE);
                        }
                        return false;
                    }
                }

                break;
            }
        }
    }

    return collision_x && collision_y && collision_z;
}



int
PlayerInputSystem::getItemsCollected()
{
    return _items_collected;
}



void
PlayerInputSystem::keyCallbackFun(GLFWwindow *window,
                                  int key,
                                  int scancode,
                                  int action,
                                  int mods)
{
    PlayerInputSystem *playerInputSystem = &getPlayerInputSystem(-1);
    playerInputSystem->keyCallback(window, key, scancode, action, mods);
}



PlayerInputSystem &
PlayerInputSystem::getPlayerInputSystem(int total_items)
{
    static PlayerInputSystem *player_input_system = nullptr;

    if (player_input_system == nullptr) {

        (void) glfwSetKeyCallback(glfwGetCurrentContext(),keyCallbackFun);
        glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        player_input_system = new PlayerInputSystem(total_items);
    }

    return *player_input_system;
}



void
PlayerInputSystem::destroyPlayerInputSystem()
{
    PlayerInputSystem *player_input_system = &getPlayerInputSystem(-1);
    delete player_input_system;
}
