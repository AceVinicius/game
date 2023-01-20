//
// Created by Vinícius Ferreira Aguiar on 09/01/23.
//

#include "GAME/CameraSystem.h"
#include "GAME/RenderSystem.h"



CameraSystem::CameraSystem()
{

}



CameraSystem::~CameraSystem()
{

}



Entity *
CameraSystem::getCurrentCamera()
{
    return _current_camera;
}



void
CameraSystem::setCurrentCamera(Entity *camera)
{
    _current_camera = camera;

    RenderSystem *render_system = &RenderSystem::getRenderSystem();
    render_system->setCurrentCamera(_current_camera);
}



CameraSystem &
CameraSystem::getCameraSystem()
{
    static CameraSystem *camera_system = nullptr;

    if (camera_system == nullptr) {
        camera_system = new CameraSystem();
    }

    return *camera_system;
}



void
CameraSystem::destroyCameraSystem()
{
    CameraSystem *camera_system = &getCameraSystem();
    delete camera_system;
}
