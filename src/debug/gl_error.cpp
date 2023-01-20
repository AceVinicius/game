//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//
#ifndef NDEBUG

# include "DEBUG/gl_error.h"



void
gl_clear_error()
{
    while (glGetError() != GL_NO_ERROR) {};
}



bool
gl_log_call(const char *function, const char *file, int line)
{
    GLenum error = glGetError();
    int error_count = 0;

    while (error != GL_NO_ERROR)
    {
        (void) fprintf(stderr, "[OpenGL error] (%x): %s:%d\n\t%s\n", error, strrchr(file, '/') + 1, line, function);
        error = glGetError();
        ++error_count;
    }

    return error_count == 0;
}



#endif
