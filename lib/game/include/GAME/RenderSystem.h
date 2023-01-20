//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#ifndef GAME_RENDERSYSTEM_H
# define GAME_RENDERSYSTEM_H

# define GL_SILENCE_DEPRECATION
# define GLFW_INCLUDE_GLU

//# include <GL/glew.h>
# include <GLFW/glfw3.h>

# include "DEBUG/gl_error.h"
# include "GAME/CameraSystem.h"
# include "GAME/Entity.h"
# include "GAME/ShaderInterface.h"
# include "GAME/VertexBuffer.h"

# include <vector>



class RenderSystem
{
private:

    GLFWwindow   *_window;
    CameraSystem *_camera_system;
    Entity       *_current_camera;

    RenderSystem();
    ~RenderSystem();

public:

    void    render(std::vector<Entity *> *entity_array);
    void    renderHUD(int collectibles, int items_collected);
    Entity *getCurrentCamera();
    void    setCurrentCamera(Entity *camera);


    static RenderSystem &getRenderSystem();
    static void          destroyRenderSystem();

};



#endif //GAME_RENDERSYSTEM_H
