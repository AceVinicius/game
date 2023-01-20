//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#ifndef GAME_VERTEXDATA_H
# define GAME_VERTEXDATA_H

# include "GAME/Vector3.h"



typedef struct {

    Vector3 position_coordinates;

} VertexDataP;

typedef struct {

    Vector3 position_coordinates;
    Vector3 normal_coordinates;

} VertexDataPN;



#endif //GAME_VERTEXDATA_H
