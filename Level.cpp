#include "Level.h"

Level::Level(int initWidth, int initHeight, int initX, int initY){
    screen_width = initWidth;
    screen_height = initHeight;
    posX = initX;
    posY = initY;
}

Level::~Level(){}

void Level::load_level(std::string path, int initWidth, int initHeight){
    level_width = initWidth;
    level_height = initHeight;
    if (!map_texture.loadFromFile(path))
        std::cout << "the level texture is failed to load\n";
    projector.setTexture(map_texture);
    sf::IntRect rect(posX, posY, screen_width, screen_height);
    projector.setTextureRect(rect);
}

void Level::draw(Graphics* gfx){
    gfx->window->draw(projector);
}
