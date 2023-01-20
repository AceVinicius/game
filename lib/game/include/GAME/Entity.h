//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#ifndef GAME_ENTITY_H
# define GAME_ENTITY_H

# define WALL          1
# define ELEVATOR_UP   2
# define ELEVATOR_DOWN 3
# define COLLECTIBLE   4
# define START         5
# define CAMERA        6
# define HUD           7

# include "GAME/Vector3.h"
# include "GAME/VertexBuffer.h"

# include <vector>



class Entity
{
private:

    VertexBuffer *_vertex_buffer;
    Vector3       _position;
    Vector3       _rotation;
    Vector3       _scale;
    Vector3       _velocity;
    Vector3       _scale_velocity;
    Vector3       _rotation_velocity;
    Vector3       _eye_vector;
    Vector3       _up_vector;
    int           _type;

public:

    VertexBuffer *getVertexBuffer();
    void          setVertexBuffer(VertexBuffer *vertex_buffer);
    Vector3       getPosition();
    void          setPosition(Vector3 position);
    Vector3       getRotation();
    void          setRotation(Vector3 rotation);
    Vector3       getScale();
    void          setScale(Vector3 scale);
    Vector3       getVelocity();
    void          setVelocity(Vector3 velocity);
    Vector3       getScaleVelocity();
    void          setScaleVelocity(Vector3 scale_velocity);
    Vector3       getRotationVelocity();
    void          setRotationVelocity(Vector3 rotation_velocity);
    Vector3       getEyeVector();
    void          setEyeVector(Vector3 newEyeVector);
    Vector3       getUpVector();
    void          setUpVector(Vector3 newUpVector);
    int           getType();
    void          setType(int type);

    Entity(VertexBuffer *vertex_buffer, Vector3 position, int type);
    ~Entity();

};



#endif //GAME_ENTITY_H
