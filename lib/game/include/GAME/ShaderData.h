//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#ifndef GAME_SHADERDATA_H
# define GAME_SHADERDATA_H

# define GL_SILENCE_DEPRECATION

//# include <GL/glew.h>
# include <GLFW/glfw3.h>

# include "GAME/Vector3.h"
# include "GAME/Vector4.h"



class ShaderData
{
private:

    Vector4 _uColorValue;
    Vector3 _uLightPosition;

public:

    Vector4 getColorValue();
    void    setColorValue(Vector4 color);
    Vector3 getLightPosition();
    void    setLightPosition(Vector3 position);

    ShaderData(Vector4 color, Vector3 position);
    ~ShaderData();

};



#endif //GAME_SHADERDATA_H
