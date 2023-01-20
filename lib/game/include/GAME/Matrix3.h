//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#ifndef GAME_MATRIX3_H
# define GAME_MATRIX3_H

# define GL_SILENCE_DEPRECATION

//# include <GL/glew.h>
# include "GLFW/glfw3.h"



typedef struct {

    GLfloat m00;
    GLfloat m01;
    GLfloat m02;
    GLfloat m10;
    GLfloat m11;
    GLfloat m12;
    GLfloat m20;
    GLfloat m21;
    GLfloat m22;

} Matrix3;



const Matrix3 identityMatrix3 = {  1.0F, 0.0F, 0.0F,
                                   0.0F, 1.0F, 0.0F,
                                   0.0F, 0.0F, 1.0F};



Matrix3 scalerMultiplyMatrix3(Matrix3 matrix, GLfloat scalerValue);
Matrix3 addMatrix3(Matrix3 matrixA, Matrix3 matrixB);
Matrix3 makeRotationMatrix3(GLfloat angle, GLfloat xAxis, GLfloat yAxis, GLfloat zAxis);



#endif //GAME_MATRIX3_H
