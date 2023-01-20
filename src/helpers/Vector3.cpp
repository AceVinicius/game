//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#include "GAME/Vector3.h"

#include <cmath>



Vector3
makeVector3(GLfloat x, GLfloat y, GLfloat z)
{
    Vector3 new_vector;

    new_vector.x = x;
    new_vector.y = y;
    new_vector.z = z;

    return new_vector;
}



Vector3
addVector3(Vector3 vectorA, Vector3 vectorB)
{
    Vector3 new_vector;

    new_vector.x = vectorA.x + vectorB.x;
    new_vector.y = vectorA.y + vectorB.y;
    new_vector.z = vectorA.z + vectorB.z;

    return new_vector;
}



Vector3
subtractVector3(Vector3 vectorA, Vector3 vectorB)
{
    Vector3 new_vector;

    new_vector.x = vectorA.x - vectorB.x;
    new_vector.y = vectorA.y - vectorB.y;
    new_vector.z = vectorA.z - vectorB.z;

    return new_vector;
}



Vector3
normalizeVector3(Vector3 vector)
{
    GLdouble lenght = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);

    Vector3 unit_vector;
    unit_vector.x = vector.x / lenght;
    unit_vector.y = vector.y / lenght;
    unit_vector.z = vector.z / lenght;

    return unit_vector;
}



Vector3
crossProductVector3(Vector3 vectorA, Vector3 vectorB)
{
    Vector3 new_vector;
    new_vector.x = vectorA.y * vectorB.z - vectorA.z * vectorB.y;
    new_vector.y = vectorA.z * vectorB.x - vectorA.x * vectorB.z;
    new_vector.z = vectorA.x * vectorB.y - vectorA.y * vectorB.x;

    return new_vector;
}



Vector3
scalerMultiplyVector3(Vector3 vectorToMultiply, GLfloat scalerValue)
{
    Vector3 new_vector;

    new_vector.x = vectorToMultiply.x * scalerValue;
    new_vector.y = vectorToMultiply.y * scalerValue;
    new_vector.z = vectorToMultiply.z * scalerValue;

    return new_vector;
}



GLfloat
dotProductVector3(Vector3 vectorA, Vector3 vectorB)
{
    return vectorA.x*vectorB.x+vectorA.y*vectorB.y+vectorA.z*vectorB.z;
}



Vector3
transformVector3(Vector3 vector, Matrix3 transformationMatrix)
{
    Vector3 new_vector;

    new_vector.x = dotProductVector3(vector, makeVector3(transformationMatrix.m00, transformationMatrix.m10, transformationMatrix.m20));
    new_vector.y = dotProductVector3(vector, makeVector3(transformationMatrix.m01, transformationMatrix.m11, transformationMatrix.m21));
    new_vector.z = dotProductVector3(vector, makeVector3(transformationMatrix.m02, transformationMatrix.m12, transformationMatrix.m22));

    return new_vector;
}