//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#ifndef GAME_GL_ERRO_H
# define GAME_GL_ERRO_H

# ifndef NDEBUG

#  define GL_SILENCE_DEPRECATION

#  include <GLFW/glfw3.h>

#  include <cassert>
#  include <csignal>
#  include <cstdio>
#  include <cstring>

//#  define ASSERT(x)  if (x) raise(SIGTRAP)
#  define GL_CALL(x) gl_clear_error(); x; assert(gl_log_call(#x, __FILE__, __LINE__))



void gl_clear_error();
bool gl_log_call(const char *function, const char *file, int line);



# else

#  define GL_CALL(x) x

# endif //NDEBUG

#endif //GAME_GL_ERRO_H
