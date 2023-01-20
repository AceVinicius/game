//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#ifndef GAME_SHADERLOADER_H
# define GAME_SHADERLOADER_H

# define GL_SILENCE_DEPRECATION

//# include <GL/glew.h>
# include "GLFW/glfw3.h"

# include "DEBUG/gl_error.h"

# include <string>



class ShaderLoader
{
private:

    GLuint _program_handle;

    GLuint compileShader(GLenum target, const char *source);

public:

    GLuint getProgramHandle();

    ShaderLoader(const std::string &source_vs, const std::string &source_fs);
    ~ShaderLoader();

};



#endif //GAME_SHADERLOADER_H
