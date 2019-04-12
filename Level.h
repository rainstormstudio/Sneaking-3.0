#pragma once
#include "Graphics.h"
#include <string>

class Level{
private:
    sf::Texture map_texture;
    sf::Sprite level;
public:
    Level();
    ~Level();
    void load_level(std::string path);
    void draw(Graphics* gfx);
};
