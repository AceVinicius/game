//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#include "GAME/Vector4.h"



Vector4 makeVector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    Vector4 new_vector;

    new_vector.x = x;
    new_vector.y = y;
    new_vector.z = z;
    new_vector.w = w;

    return new_vector;
}
