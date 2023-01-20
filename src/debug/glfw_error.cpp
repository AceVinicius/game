//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//
#ifndef NDEBUG

# include "DEBUG/glfw_error.h"



void
error_callback(int error, const char *description)
{
    (void) fprintf(stderr, "Error: %s\n", description);
}



#endif
