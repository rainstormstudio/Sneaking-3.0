#include "Level.h"

Level::Level(){}

Level::~Level(){}

void Level::load_level(std::string path){
    if (!map_texture.loadFromFile(path))
        std::cout << "the level texture is failed to load\n";
    level.setTexture(map_texture);
}

void Level::draw(Graphics* gfx){
    gfx->window->draw(level);
}
