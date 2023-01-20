//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#ifndef GAME_MOVEMENTSYSTEM_H
# define GAME_MOVEMENTSYSTEM_H

# define GL_SILENCE_DEPRECATION

//# include <GL/glew.h>
# include <GLFW/glfw3.h>

# include "GAME/Entity.h"
# include "GAME/Vector3.h"



class MovementSystem
{
private:

    MovementSystem();
    ~MovementSystem();

public:

    void update(std::vector<Entity *> *entity_array);

    static MovementSystem &getMovementSystem();
    static void            destroyMovementSystem();

};



#endif //GAME_MOVEMENTSYSTEM_H
