//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#include "GAME/MovementSystem.h"



MovementSystem::MovementSystem()
{

}



MovementSystem::~MovementSystem()
{

}



void
MovementSystem::update(std::vector<Entity *> *entity_array)
{
    for (auto entity : *entity_array) {
        entity->setPosition(addVector3(entity->getPosition(), entity->getVelocity()));
        entity->setScale(addVector3(entity->getScale(), entity->getScaleVelocity()));
        entity->setRotation(addVector3(entity->getRotation(), entity->getRotationVelocity()));
    }
}



MovementSystem &
MovementSystem::getMovementSystem()
{
    static MovementSystem* movement_system = nullptr;

    if (movement_system == nullptr) {
        movement_system = new MovementSystem();
    }

    return *movement_system;
}



void
MovementSystem::destroyMovementSystem()
{
    MovementSystem *movementSystem = &getMovementSystem();
    delete movementSystem;
}
