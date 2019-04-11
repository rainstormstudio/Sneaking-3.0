#pragma once
#include "Graphics.h"
#include <string>

class Level{
public:
    sf::Texture map_texture;
    sf::Sprite level;

    Level();
    ~Level();
    void load_level(std::string path);
    void draw(Graphics* gfx);
};
