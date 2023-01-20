//
// Created by Vinícius Ferreira Aguiar on 09/01/23.
//

#ifndef GAME_SCENE_H
# define GAME_SCENE_H

# include "GAME/Entity.h"

# include <cstdio>
# include <vector>



class Scene
{
private:

    std::vector<Entity *> *_children;
    std::vector<Entity *> *_hud;
    int                    _collectibles;
    int                    _grid_size;
    int                    _levels;

    int  getGridSize(FILE *file_p);
    int  getLevels(FILE *file_p, int grid_size);

public:

    std::vector<Entity *> *getChildren();
    std::vector<Entity *> *getHud();
    int                    getCollectibles();

    Scene(const char *map);
    ~Scene();

};



#endif //GAME_SCENE_H
