//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#ifndef GAME_GLFW_ERROR_H
# define GAME_GLFW_ERROR_H

# ifndef NDEBUG

#  define GL_SILENCE_DEPRECATION

#  include "DEBUG/glfw_error.h"

#  include <cstdio>

#  define GLFW_SETUP() (void) glfwSetErrorCallback(error_callback)



void error_callback(int error, const char* description);



# else

#  define GLFW_SETUP()

# endif //NDEBUG

#endif //GAME_GLFW_ERROR_H
