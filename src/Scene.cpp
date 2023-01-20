//
// Created by Vinícius Ferreira Aguiar on 09/01/23.
//

#include "GAME/Scene.h"
#include "GAME/CameraSystem.h"
#include "GAME/PlayerInputSystem.h"
#include "GAME/ResourceManager.h"



Scene::Scene(const char *map)
{
    _children = new std::vector<Entity *>();
    _collectibles = 0;

    ResourceManager *resource_manager = &ResourceManager::getResourceManager();

    FILE *map_p = fopen(map, "r");
    if (map_p == nullptr) {
        return;
    }

    _grid_size = getGridSize(map_p);
    _levels = getLevels(map_p, _grid_size);
    char grid[ _grid_size ][ _grid_size ][ _levels ];
    char *line = nullptr;
    Entity *camera;
    size_t len = 0U;

    for (int level = 0; level < _levels; ++level) {
        for (int i = 0; i < _grid_size; ++i) {
            (void) getline(&line, &len, map_p);
            char *token = strtok(line, " ");

            for (int j = 0; j < _grid_size; ++j) {
                grid[ i ][ j ][ level ] = token[ 0 ];
                token = strtok(nullptr, " ");
            }
        }
    }

    (void) fclose(map_p);

    if (line != nullptr) {
        free(line);
    }

    for (int level = 0; level < _levels * 2 - 1; ++level) {
        for (int x = 0; x < _grid_size; ++x) {
            for (int z = 0; z < _grid_size; ++z) {

                if (level % 2 == 0) {

                    switch (grid[ x ][ z ][ level / 2 ]) {
                        case '1': {
                            auto *block = new Entity(resource_manager->getVertexBufferArray()->at(0U),
                                                     makeVector3(static_cast<float>(x), static_cast<float>(level), static_cast<float>(z)),
                                                     WALL);
                            _children->push_back(block);

                            break;
                        }

                        case '2': {
                            auto *elevator_up = new Entity(resource_manager->getVertexBufferArray()->at(1U),
                                                           makeVector3(static_cast<float>(x), static_cast<float>(level), static_cast<float>(z)),
                                                           ELEVATOR_UP);
                            _children->push_back(elevator_up);
                            break;
                        }

                        case '3': {
                            auto *elevator_down = new Entity(resource_manager->getVertexBufferArray()->at(2U),
                                                             makeVector3(static_cast<float>(x), static_cast<float>(level), static_cast<float>(z)),
                                                             ELEVATOR_DOWN);
                            _children->push_back(elevator_down);
                            break;
                        }

                        case '4': {
                            auto *collectible = new Entity(resource_manager->getVertexBufferArray()->at(3U),
                                                           makeVector3(static_cast<float>(x), static_cast<float>(level), static_cast<float>(z)),
                                                           COLLECTIBLE);
                            _children->push_back(collectible);

                            collectible->setScale(makeVector3(0.10F, 0.10F, 0.10F));
                            collectible->setRotation(makeVector3(60.0F, 45.00F, 0.00F));

                            ++_collectibles;
                            break;
                        }

                        case 'x': {
                            auto *start = new Entity(resource_manager->getVertexBufferArray()->at(0U),
                                                     makeVector3(static_cast<float>(x), static_cast<float>(level), static_cast<float>(z)),
                                                     START);
                            _children->push_back(start);

                            camera = new Entity(nullptr,
                                                makeVector3(static_cast<float>(x), static_cast<float>(level), static_cast<float>(z)),
                                                      CAMERA);
                            camera->setEyeVector(normalizeVector3(makeVector3(0.0F, 0.0F, 5.0F)));
                            _children->push_back(camera);

                            break;
                        }
                    }

                } else {

                    auto *block = new Entity(resource_manager->getVertexBufferArray()->at(0U),
                                             makeVector3(static_cast<float>(x), static_cast<float>(level), static_cast<float>(z)),
                                              WALL);
                    _children->push_back(block);

                }
            }
        }
    }

    CameraSystem *camera_system = &CameraSystem::getCameraSystem();
    PlayerInputSystem *player_input_system = &PlayerInputSystem::getPlayerInputSystem(_collectibles);

    player_input_system->setCurrentPlayer(camera);
    camera_system->setCurrentCamera(camera);
}



Scene::~Scene()
{
    for (auto & iterator : *_children) {
        delete iterator;
    }

    delete _children;
}



std::vector<Entity *> *
Scene::getChildren()
{
    return _children;
}



int
Scene::getGridSize(FILE *file_p)
{
    char *line = nullptr;
    size_t len = 0U;
    int grid_size = 0;

    (void) getline(&line, &len, file_p);

    char *token = strtok(line, " ");
    while (token != nullptr) {
        token = strtok(nullptr, " ");
        ++grid_size;
    }

    rewind(file_p);

    if (line != nullptr) {
        free(line);
    }

    return grid_size;
}



int
Scene::getLevels(FILE *file_p, int grid_size)
{
    char *line = nullptr;
    ssize_t read;
    size_t len = 0U;
    int line_count = 0;

    while ((read = getline(&line, &len, file_p)) != -1) {
        ++line_count;
    }

    rewind(file_p);

    if (line != nullptr) {
        free(line);
    }

    return line_count / grid_size;
}



int
Scene::getCollectibles()
{
    return _collectibles;
}



std::vector<Entity *> *
Scene::getHud()
{
    return _hud;
}
