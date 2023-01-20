//
// Created by Vinícius Ferreira Aguiar on 09/01/23.
//

#ifndef GAME_CAMERASYSTEM_H
# define GAME_CAMERASYSTEM_H

# include "GAME/Entity.h"



class CameraSystem
{
private:

    Entity *_current_camera;

    CameraSystem();
    ~CameraSystem();

public:

    Entity *getCurrentCamera();
    void    setCurrentCamera(Entity *camera);

    static CameraSystem &getCameraSystem();
    static void          destroyCameraSystem();

};



#endif //GAME_CAMERASYSTEM_H
