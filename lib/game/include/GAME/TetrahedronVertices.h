//
// Created by Vinícius Ferreira Aguiar on 08/01/23.
//

#ifndef GAME_TETRAHEDRONVERTICES_H
# define GAME_TETRAHEDRONVERTICES_H

# include "GAME/VertexData.h"



VertexDataP tetrahedron_vertices[] = {
        -1.0,  1.0, -1.0, // V1
        1.0, -1.0, -1.0, // V2
        -1.0, -1.0,  1.0, // V3

        1.0,  1.0,  1.0, // V0
        -1.0, -1.0,  1.0, // V3
        1.0, -1.0, -1.0, // V2

        1.0,  1.0,  1.0, // V0
        -1.0,  1.0, -1.0, // V1
        -1.0, -1.0,  1.0, // V3

        1.0,  1.0,  1.0, // V0
        1.0, -1.0, -1.0, // V2
        -1.0,  1.0, -1.0 // V1
};



#endif //GAME_TETRAHEDRONVERTICES_H
