//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#include "GAME/ShaderData.h"



ShaderData::ShaderData(Vector4 color, Vector3 position)
    : _uColorValue(color)
    , _uLightPosition(position)
{

}



ShaderData::~ShaderData()
{

}



Vector4
ShaderData::getColorValue()
{
    return _uColorValue;
}



void
ShaderData::setColorValue(Vector4 color)
{
    _uColorValue = color;
}



Vector3
ShaderData::getLightPosition()
{
    return _uLightPosition;
}



void
ShaderData::setLightPosition(Vector3 position)
{
    _uLightPosition = position;
}
