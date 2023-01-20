//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#ifndef GAME_SHADERINTERFACE_H
# define GAME_SHADERINTERFACE_H

# include "GAME/ShaderLoader.h"

# include <cstdio>
# include <cstdlib>
# include <string>



class ShaderInterface
{
private:

    ShaderLoader *_shader;
    GLint         _aPositionVertex;
    GLint         _aPositionNormal;
    GLint         _uLightPosition;
    GLint         _uColor;
    char         *_vertex_shader_string;
    char         *_fragment_shader_string;

    char *loadTextFromFile(const char *file);

public:

    GLuint getProgramHandle();
    GLint  getPositionVertex();
    GLint  getPositionNormal();
    GLint  getLightPosition();
    GLint  getColor();

    ShaderInterface(const std::string &vs, const std::string &fs);
    ~ShaderInterface();

};



#endif //GAME_SHADERINTERFACE_H
