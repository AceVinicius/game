//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#include "GAME/Entity.h"



Entity::Entity(VertexBuffer *vertex_buffer, Vector3 position, int type)
    : _vertex_buffer(vertex_buffer)
    , _position(position)
    , _type(type)
    , _rotation(makeVector3(0.0F, 0.0F, 0.0F))
    , _scale(makeVector3(1.0F, 1.0F, 1.0F))
    , _velocity(makeVector3(0.0F, 0.0F, 0.0F))
    , _scale_velocity(makeVector3(0.0F, 0.0F, 0.0F))
    , _rotation_velocity(makeVector3(0.0F, 0.0F, 0.0F))
    , _eye_vector(makeVector3(0.0F, 0.0F, 0.0F))
    , _up_vector(makeVector3(0.0F, 1.0F, 0.0F))
{

}



Entity::~Entity()
{

}



VertexBuffer *
Entity::getVertexBuffer()
{
    return _vertex_buffer;
}



void
Entity::setVertexBuffer(VertexBuffer *vertex_buffer)
{
    _vertex_buffer = vertex_buffer;
}



Vector3
Entity::getPosition()
{
    return _position;
}



void
Entity::setPosition(Vector3 position)
{
    _position = position;
}



Vector3
Entity::getRotation()
{
    return _rotation;
}



void
Entity::setRotation(Vector3 rotation)
{
    _rotation = rotation;
}



Vector3
Entity::getScale()
{
    return _scale;
}



void
Entity::setScale(Vector3 scale)
{
    _scale = scale;
}



Vector3
Entity::getVelocity()
{
    return _velocity;
}



void
Entity::setVelocity(Vector3 velocity)
{
    _velocity = velocity;
}



Vector3
Entity::getScaleVelocity()
{
    return _scale_velocity;
}



void
Entity::setScaleVelocity(Vector3 scale_velocity)
{
    _scale_velocity = scale_velocity;
}



Vector3
Entity::getRotationVelocity()
{
    return _rotation_velocity;
}



void
Entity::setRotationVelocity(Vector3 rotation_velocity)
{
    _rotation_velocity = rotation_velocity;
}



Vector3
Entity::getEyeVector()
{
    return _eye_vector;
}



void
Entity::setEyeVector(Vector3 eye_vector)
{
    _eye_vector = eye_vector;
}



Vector3
Entity::getUpVector()
{
    return _up_vector;
}



void Entity::setUpVector(Vector3 up_vector)
{
    _up_vector = up_vector;
}



int Entity::getType()
{
    return _type;
}



void
Entity::setType(int type)
{
    _type = type;
}
