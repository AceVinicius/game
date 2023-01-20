//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#ifndef GAME_VECTOR4_H
# define GAME_VECTOR4_H

# define GL_SILENCE_DEPRECATION

//# include <GL/glew.h>
# include <GLFW/glfw3.h>



typedef struct {

    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;

} Vector4;



Vector4 makeVector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);



#endif //GAME_VECTOR4_H
