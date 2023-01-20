//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#ifndef GAME_VERTEXBUFFER_H
# define GAME_VERTEXBUFFER_H

# define GL_SILENCE_DEPRECATION

//# include <GL/glew.h>
# include <GLFW/glfw3.h>

# include "DEBUG/gl_error.h"
# include "GAME/ShaderData.h"
# include "GAME/ShaderInterface.h"



class VertexBuffer
{
private:

    GLuint           _vertex_buffer_id;
    ShaderInterface *_shader;
    ShaderData      *_shader_data;
    GLenum           _mode;
    GLsizei          _count;
    GLsizei          _stride;
    GLvoid          *_position_offset;
    GLvoid          *_normal_offset;

public:

    GLuint           getVertexBufferID();
    ShaderInterface *getShader();
    ShaderData      *getShaderData();
    void             renderVertexBuffer();
    void             configureVertexAttributes();

    VertexBuffer(const GLvoid *data,
                 GLsizeiptr size,
                 GLenum mode,
                 GLsizei count,
                 GLsizei stride,
                 ShaderInterface *shader,
                 ShaderData *shader_data,
                 GLvoid *position_offset,
                 GLvoid *normal_offset);
    ~VertexBuffer();

};



#endif //GAME_VERTEXBUFFER_H
