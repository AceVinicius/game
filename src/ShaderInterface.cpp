//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#include "GAME/ShaderInterface.h"



ShaderInterface::ShaderInterface(const std::string &vs, const std::string &fs)
{
    _vertex_shader_string = loadTextFromFile(vs.c_str());
    _fragment_shader_string = loadTextFromFile(fs.c_str());

    _shader = new ShaderLoader(_vertex_shader_string, _fragment_shader_string);

    free(_vertex_shader_string);
    free(_fragment_shader_string);

    GL_CALL(_aPositionVertex = glGetAttribLocation(_shader->getProgramHandle(), "aPositionVertex"));
    GL_CALL(_aPositionNormal = glGetAttribLocation(_shader->getProgramHandle(), "aPositionNormal"));
    GL_CALL(_uLightPosition = glGetUniformLocation(_shader->getProgramHandle(), "uLightPosition"));
    GL_CALL(_uColor = glGetUniformLocation(_shader->getProgramHandle(), "uColor"));
}



ShaderInterface::~ShaderInterface()
{
    delete _shader;
}



char *
ShaderInterface::loadTextFromFile(const char *file)
{
    FILE *current_file = fopen(file, "r");

    if (current_file == nullptr) {
        return nullptr;
    }

    (void) fseek(current_file, 0, SEEK_END);

    long count = ftell(current_file);
    rewind (current_file);

    char *data = (char *) calloc(count + 1, sizeof(char));
    if (data == nullptr) {
        (void) fclose(current_file);
        return nullptr;
    }

    count = fread((void *) data, sizeof(char), count, current_file);
    data[count] = '\0';

    (void) fclose(current_file);

    return data;
}



GLuint
ShaderInterface::getProgramHandle()
{
    return _shader->getProgramHandle();
}



GLint
ShaderInterface::getPositionVertex()
{
    return _aPositionVertex;
}



GLint
ShaderInterface::getPositionNormal()
{
    return _aPositionNormal;
}



GLint
ShaderInterface::getLightPosition()
{
    return _uLightPosition;
}



GLint
ShaderInterface::getColor()
{
    return _uColor;
}

