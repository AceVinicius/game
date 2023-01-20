//
// Created by Vinícius Ferreira Aguiar on 07/01/23.
//

#include "GAME/GameManager.h"



int
main(int argc, const char **argv)
{
    if (argc == 2) {
        GameManager *game_manager = &GameManager::getGameManager(argv[ 1 ]);
        game_manager->runGameLoop();
        GameManager::destroyGameManager();
    }

    return 0;
}
