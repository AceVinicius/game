//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#include "GAME/RenderSystem.h"



RenderSystem::RenderSystem()
    : _window(glfwGetCurrentContext())
    , _camera_system(&CameraSystem::getCameraSystem())
{
    _current_camera = _camera_system->getCurrentCamera();
}



RenderSystem::~RenderSystem()
{

}



void
RenderSystem::render(std::vector<Entity *> *entity_array)
{
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

    for (auto entity : *entity_array) {

        if (entity->getType() == CAMERA || entity->getType() == START) {
            continue;
        }

        GL_CALL(glUseProgram(entity->getVertexBuffer()->getShader()->getProgramHandle()));
        GL_CALL(glLoadIdentity());

        GL_CALL(gluLookAt(_current_camera->getPosition().x,
                          _current_camera->getPosition().y,
                          _current_camera->getPosition().z,
                          _current_camera->getEyeVector().x,
                          _current_camera->getEyeVector().y,
                          _current_camera->getEyeVector().z,
                          _current_camera->getUpVector().x,
                          _current_camera->getUpVector().y,
                          _current_camera->getUpVector().z));

        GL_CALL(glTranslatef(entity->getPosition().x, entity->getPosition().y, entity->getPosition().z));

        GL_CALL(glRotatef(entity->getRotation().x, 0.0F, 0.0F, 1.0F));
        GL_CALL(glRotatef(entity->getRotation().y, 0.0F, 1.0F, 0.0F));
        GL_CALL(glRotatef(entity->getRotation().z, 1.0F, 0.0F, 0.0F));

        GL_CALL(glScalef(entity->getScale().x, entity->getScale().y, entity->getScale().z));

        GL_CALL(glUniform4f(entity->getVertexBuffer()->getShader()->getColor(),
                            entity->getVertexBuffer()->getShaderData()->getColorValue().x,
                            entity->getVertexBuffer()->getShaderData()->getColorValue().y,
                            entity->getVertexBuffer()->getShaderData()->getColorValue().z,
                            entity->getVertexBuffer()->getShaderData()->getColorValue().w));

        GL_CALL(glUniform3f(entity->getVertexBuffer()->getShader()->getLightPosition(),
                            entity->getVertexBuffer()->getShaderData()->getLightPosition().x,
                            entity->getVertexBuffer()->getShaderData()->getLightPosition().y,
                            entity->getVertexBuffer()->getShaderData()->getLightPosition().z));

        entity->getVertexBuffer()->configureVertexAttributes();
        entity->getVertexBuffer()->renderVertexBuffer();
    }
}



void
RenderSystem::renderHUD(int collectibles, int items_collected)
{
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    GL_CALL(glUseProgram(0));
    GL_CALL(glMatrixMode(GL_PROJECTION));
    GL_CALL(glPushMatrix());
    GL_CALL(glLoadIdentity());
    GL_CALL(glOrtho(0.0F, mode->width * 1.0F, mode->height * 1.0F   , 0.0F, -1.0F, 10.0F));
    GL_CALL(glMatrixMode(GL_MODELVIEW));
    GL_CALL(glPushMatrix());
    GL_CALL(glLoadIdentity());

    GL_CALL(glDisable(GL_LIGHTING));
    GL_CALL(glDisable(GL_CULL_FACE));
    GL_CALL(glClear(GL_DEPTH_BUFFER_BIT));

    glBegin(GL_QUADS);
        glColor3f(0.0F, 1.0F, 0.0F);
        for (int i = 0; i < items_collected; ++i) {
            glVertex2f(20.0F + 40.0F * static_cast<float>(i), 40.0F);
            glVertex2f(20.0F + 40.0F * static_cast<float>(i), 20.0F);
            glVertex2f(40.0F + 40.0F * static_cast<float>(i), 20.0F);
            glVertex2f(40.0F + 40.0F * static_cast<float>(i), 40.0F);
        }
        glColor3f(1.0F, 0.0F, 0.0F);
        for (int i = items_collected; i < collectibles; ++i) {
            glVertex2f(20.0F + 40.0F * static_cast<float>(i), 40.0F);
            glVertex2f(20.0F + 40.0F * static_cast<float>(i), 20.0F);
            glVertex2f(40.0F + 40.0F * static_cast<float>(i), 20.0F);
            glVertex2f(40.0F + 40.0F * static_cast<float>(i), 40.0F);
        }
    glEnd();

    GL_CALL(glMatrixMode(GL_PROJECTION));
    GL_CALL(glPopMatrix());
    GL_CALL(glMatrixMode(GL_MODELVIEW));
    GL_CALL(glPopMatrix());

    GL_CALL(glEnable(GL_CULL_FACE));
    GL_CALL(glEnable(GL_LIGHTING));
}



Entity *
RenderSystem::getCurrentCamera()
{
    return _current_camera;
}



void
RenderSystem::setCurrentCamera(Entity *camera)
{
    _current_camera = camera;
}



RenderSystem &
RenderSystem::getRenderSystem()
{
    static RenderSystem *render_system = nullptr;

    if (render_system == nullptr) {
        render_system = new RenderSystem();

        GL_CALL(glClearColor(1.0F, 1.0F, 1.0F, 1.0F));
        GL_CALL(glClearDepth(1.0f));

        const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

        GL_CALL(glMatrixMode(GL_PROJECTION));
        GL_CALL(gluPerspective(65.0F, (mode->width * 1.0F) / (mode->height * 1.0F), 0.05, 1000));
        GL_CALL(glViewport(0.0F, 0.0F, mode->width * 1.0F, mode->height * 1.0F));
        GL_CALL(glMatrixMode(GL_MODELVIEW));
        GL_CALL(glEnable(GL_CULL_FACE));
    }

    return *render_system;
}



void
RenderSystem::destroyRenderSystem()
{
    RenderSystem *render_system = &getRenderSystem();
    delete render_system;
}
