//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#include "GAME/VertexBuffer.h"



VertexBuffer::VertexBuffer(const GLvoid *data,
                           GLsizeiptr size,
                           GLenum mode,
                           GLsizei count,
                           GLsizei stride,
                           ShaderInterface *shader,
                           ShaderData *shader_data,
                           GLvoid *position_offset,
                           GLvoid *normal_offset)
    : _mode(mode)
    , _count(count)
    , _stride(stride)
    , _shader(shader)
    , _shader_data(shader_data)
    , _position_offset(position_offset)
    , _normal_offset(normal_offset)
{
    GL_CALL(glGenBuffers(1, &_vertex_buffer_id));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer_id));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}



VertexBuffer::~VertexBuffer()
{
    GL_CALL(glDeleteBuffers(1, &_vertex_buffer_id));
    _vertex_buffer_id = 0U;
}



GLuint
VertexBuffer::getVertexBufferID()
{
    return _vertex_buffer_id;
}



ShaderInterface *
VertexBuffer::getShader() {
    return _shader;
}



ShaderData *
VertexBuffer::getShaderData() {
    return _shader_data;
}



void
VertexBuffer::renderVertexBuffer()
{
    GL_CALL(glDrawArrays(_mode, 0, _count));
}



void
VertexBuffer::configureVertexAttributes()
{
    GLint position_vertex = _shader->getPositionVertex();
    GLint position_normal = _shader->getPositionNormal();

    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer_id));

    if (position_vertex != -1) {
        GL_CALL(glEnableVertexAttribArray(position_vertex));
        GL_CALL(glVertexAttribPointer(position_vertex, 3, GL_FLOAT, GL_FALSE, _stride, _position_offset));
    }

    if (position_normal != -1) {
        GL_CALL(glEnableVertexAttribArray(position_normal));
        GL_CALL(glVertexAttribPointer(position_normal, 3, GL_FLOAT, GL_FALSE, _stride, _normal_offset));
    }
}
