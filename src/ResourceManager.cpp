//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#include "GAME/ResourceManager.h"
#include "GAME/CubeVertices.h"
#include "GAME/TetrahedronVertices.h"



ResourceManager::ResourceManager()
{
    _shader_array = new std::vector<ShaderInterface *>();
    _vertex_buffer_array = new std::vector<VertexBuffer *>();

    auto *color_shader = new ShaderInterface("../src/shaders/ColorShader.vert", "../src/shaders/ColorShader.frag");
    auto *light_shader = new ShaderInterface("../src/shaders/LightShader.vert", "../src/shaders/LightShader.frag");
    _shader_array->push_back(color_shader);
    _shader_array->push_back(light_shader);

    _wall_shader_data = new ShaderData(makeVector4(192.0F / 255, 192.0F / 255, 192.0F / 255, 1.0F),
                                       makeVector3(1.0F, 1.5F, 1.0F));

    _elevator_up_shader_data = new ShaderData(makeVector4(117.0F / 255, 252.0F / 255, 253.0F / 255, 0.25F),
                                              makeVector3(1.0F, 1.5F, 1.0F));

    _elevator_down_shader_data = new ShaderData(makeVector4(55.0F / 255, 125.0F / 255, 246.0F / 255, 0.25F),
                                                makeVector3(1.0F, 1.5F, 1.0F));

    _collectible_shader_data = new ShaderData(makeVector4(237.0F / 255, 134.0F / 255, 50.0F / 255, 1.0F),
                                              makeVector3(2.0F, 3.0F, 3.0F));

    auto wall_vertex_buffer = new VertexBuffer(cube_vertices,
                                               sizeof(cube_vertices),
                                               GL_TRIANGLES,
                                               36,
                                               sizeof(VertexDataPN),
                                               _shader_array->at(1U),
                                               _wall_shader_data,
                                               (GLvoid *) offsetof(VertexDataPN, position_coordinates),
                                               (GLvoid *) offsetof(VertexDataPN, normal_coordinates));

    auto elevator_up_vertex_buffer = new VertexBuffer(cube_vertices,
                                                      sizeof(cube_vertices),
                                                      GL_TRIANGLES,
                                                      36,
                                                      sizeof(VertexDataPN),
                                                      _shader_array->at(1U),
                                                      _elevator_up_shader_data,
                                                      (GLvoid *) offsetof(VertexDataPN, position_coordinates),
                                                      (GLvoid *) offsetof(VertexDataPN, normal_coordinates));

    auto elevator_down_vertex_buffer = new VertexBuffer(cube_vertices,
                                                        sizeof(cube_vertices),
                                                        GL_TRIANGLES,
                                                        36,
                                                        sizeof(VertexDataPN),
                                                        _shader_array->at(1U),
                                                        _elevator_down_shader_data,
                                                        (GLvoid *) offsetof(VertexDataPN, position_coordinates),
                                                        (GLvoid *) offsetof(VertexDataPN, normal_coordinates));

    auto collectible_vertex_buffer = new VertexBuffer(tetrahedron_vertices,
                                                      sizeof(tetrahedron_vertices),
                                                      GL_TRIANGLES,
                                                      12,
                                                      sizeof(VertexDataP),
                                                      _shader_array->at(1U),
                                                      _collectible_shader_data,
                                                      (GLvoid *) offsetof(VertexDataP, position_coordinates),
                                                      nullptr);

    _vertex_buffer_array->push_back(wall_vertex_buffer);
    _vertex_buffer_array->push_back(elevator_up_vertex_buffer);
    _vertex_buffer_array->push_back(elevator_down_vertex_buffer);
    _vertex_buffer_array->push_back(collectible_vertex_buffer);
}



ResourceManager::~ResourceManager()
{
    delete _wall_shader_data;
    delete _elevator_up_shader_data;
    delete _elevator_down_shader_data;
    delete _collectible_shader_data;

    for (auto & iterator : *_shader_array) {
        delete iterator;
    }
    delete _shader_array;

    for (auto & iterator : *_vertex_buffer_array) {
        delete iterator;
    }
    delete _vertex_buffer_array;
}



std::vector<ShaderInterface *> *
ResourceManager::getShaderArray()
{
    return _shader_array;
}



std::vector<VertexBuffer *> *
ResourceManager::getVertexBufferArray()
{
    return _vertex_buffer_array;
}



ResourceManager &
ResourceManager::getResourceManager()
{
    static ResourceManager *resource_manager = nullptr;

    if (resource_manager == nullptr) {
        resource_manager = new ResourceManager();
    }

    return *resource_manager;
}



void ResourceManager::destroyResourceManager()
{
    ResourceManager *resource_manager = &getResourceManager();
    delete resource_manager;
}
