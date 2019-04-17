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

void Level::update_projector(float playerX, float playerY){
    if (playerX - posX >= screen_width * 0.75)
        posX += playerX - posX - screen_width * 0.75;
    if (playerX - posX <= screen_width * 0.25)
        posX += playerX - posX - screen_width * 0.25;
    if (playerY - posY >= screen_height * 0.75)
        posY += playerY - posY - screen_height * 0.75;
    if (playerY - posY <= screen_height * 0.25)
        posY += playerY - posY - screen_height * 0.25;
    sf::IntRect rect(posX, posY, screen_width, screen_height);
    projector.setTextureRect(rect);
}

void Level::draw(Graphics* gfx){
    sf::IntRect rect(posX, posY, screen_width, screen_height);
    projector.setTextureRect(rect);
    gfx->window->draw(projector);
}
