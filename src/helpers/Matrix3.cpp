//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#include "GAME/Matrix3.h"

#include <cmath>



Matrix3
scalerMultiplyMatrix3(Matrix3 matrix, GLfloat scalerValue)
{
    Matrix3 new_matrix;
    
    new_matrix.m00 = matrix.m00 * scalerValue;
    new_matrix.m01 = matrix.m01 * scalerValue;
    new_matrix.m02 = matrix.m02 * scalerValue;
    new_matrix.m10 = matrix.m10 * scalerValue;
    new_matrix.m11 = matrix.m11 * scalerValue;
    new_matrix.m12 = matrix.m12 * scalerValue;
    new_matrix.m20 = matrix.m20 * scalerValue;
    new_matrix.m21 = matrix.m21 * scalerValue;
    new_matrix.m22 = matrix.m22 * scalerValue;

    return new_matrix;
}



Matrix3
addMatrix3(Matrix3 matrixA, Matrix3 matrixB)
{
    Matrix3 new_matrix;

    new_matrix.m00 = matrixA.m00 + matrixB.m00;
    new_matrix.m01 = matrixA.m01 + matrixB.m01;
    new_matrix.m02 = matrixA.m02 + matrixB.m02;
    new_matrix.m10 = matrixA.m10 + matrixB.m10;
    new_matrix.m11 = matrixA.m11 + matrixB.m11;
    new_matrix.m12 = matrixA.m12 + matrixB.m12;
    new_matrix.m20 = matrixA.m20 + matrixB.m20;
    new_matrix.m21 = matrixA.m21 + matrixB.m21;
    new_matrix.m22 = matrixA.m22 + matrixB.m22;

    return new_matrix;
}



Matrix3
makeRotationMatrix3(GLfloat angle, GLfloat xAxis, GLfloat yAxis, GLfloat zAxis)
{
    GLfloat x = xAxis;
    GLfloat y = yAxis;
    GLfloat z = zAxis;

    auto cosine = (GLfloat) cos(angle);

    Matrix3 cosineMatrix = scalerMultiplyMatrix3(identityMatrix3, cosine);

    Matrix3 tangentMatrix = { x * x, x * y, x * z,
                              x * y, y * y, y * z,
                              x * z, y * z, z * z};
    GLfloat tangent = 1.0F - cosine;


    tangentMatrix = scalerMultiplyMatrix3(tangentMatrix, tangent);


    Matrix3 sineMatrix = { 0.0F,    z,   -y,
                             -z, 0.0F,    x,
                              y,   -x, 0.0F };

    auto sine = (GLfloat) sin(angle);

    sineMatrix = scalerMultiplyMatrix3(sineMatrix, sine);

    return addMatrix3(addMatrix3(cosineMatrix, tangentMatrix), sineMatrix);
}
