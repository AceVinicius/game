//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#ifndef GAME_VECTOR3_H
# define GAME_VECTOR3_H

# define GL_SILENCE_DEPRECATION

//# include <GL/glew.h>
# include <GLFW/glfw3.h>

#include "GAME/Matrix3.h"



typedef struct {

    GLfloat x;
    GLfloat y;
    GLfloat z;

} Vector3;



Vector3 makeVector3(GLfloat x, GLfloat y, GLfloat z);
Vector3 addVector3(Vector3 vectorA, Vector3 vectorB);
Vector3 subtractVector3(Vector3 vectorA, Vector3 vectorB);
Vector3 normalizeVector3(Vector3 vector);
Vector3 scalerMultiplyVector3(Vector3 vectorToMultiply, GLfloat scalerValue);
Vector3 crossProductVector3(Vector3 vectorA, Vector3 vectorB);
GLfloat dotProductVector3(Vector3 vectorA, Vector3 vectorB);
Vector3 transformVector3(Vector3 vector, Matrix3 transformationMatrix);



#endif //GAME_VECTOR3_H
