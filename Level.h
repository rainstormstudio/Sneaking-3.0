#pragma once
#include "Graphics.h"
#include <string>

class Level{
private:
    int screen_width;
    int screen_height;
    int level_width;
    int level_height;
    int posX, posY;
    sf::Texture map_texture;
    sf::Sprite projector;
public:
    Level(int initWidth, int initHeight, int initX, int initY);
    ~Level();
    void load_level(std::string path, int initWidth, int initHeight);
    void update_projector(float playerX, float playerY);
    void draw(Graphics* gfx);
};
