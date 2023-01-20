//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#ifndef GAME_RESOURCEMANAGER_H
# define GAME_RESOURCEMANAGER_H

# include "GAME/ShaderData.h"
# include "GAME/ShaderInterface.h"
# include "GAME/VertexBuffer.h"

# include <vector>



class ResourceManager
{
private:

    std::vector<ShaderInterface *> *_shader_array;
    std::vector<VertexBuffer *>    *_vertex_buffer_array;
    ShaderData                     *_wall_shader_data;
    ShaderData                     *_elevator_up_shader_data;
    ShaderData                     *_elevator_down_shader_data;
    ShaderData                     *_collectible_shader_data;
    ShaderData                     *_hud_collected_shader_data;
    ShaderData                     *_hud_to_collect_shader_data;

    ResourceManager();
    ~ResourceManager();

public:

    std::vector<ShaderInterface *> *getShaderArray();
    std::vector<VertexBuffer *>    *getVertexBufferArray();

    static ResourceManager &getResourceManager();
    static void             destroyResourceManager();

};



#endif //GAME_RESOURCEMANAGER_H
