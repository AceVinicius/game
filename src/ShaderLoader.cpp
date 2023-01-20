//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#include "GAME/ShaderLoader.h"



ShaderLoader::ShaderLoader(const std::string &source_vs, const std::string &source_fs)
{
    GL_CALL(_program_handle = glCreateProgram());

    GLuint vertex_shader = compileShader(GL_VERTEX_SHADER, source_vs.c_str());
    GLuint fragment_shader = compileShader(GL_FRAGMENT_SHADER, source_fs.c_str());

    GL_CALL(glAttachShader(_program_handle, vertex_shader));
    GL_CALL(glAttachShader(_program_handle, fragment_shader));

    GL_CALL(glLinkProgram(_program_handle));

    GL_CALL(glDeleteShader(vertex_shader));
    GL_CALL(glDeleteShader(fragment_shader));
}



ShaderLoader::~ShaderLoader()
{
    glDeleteProgram(_program_handle);
}



GLuint
ShaderLoader::compileShader(GLenum shader, const char *source)
{
    GL_CALL(GLuint shader_handle = glCreateShader(shader));

    GL_CALL(glShaderSource(shader_handle, 1, &source, nullptr));
    GL_CALL(glCompileShader(shader_handle));

    return shader_handle;
}



GLuint
ShaderLoader::getProgramHandle()
{
    return _program_handle;
}
