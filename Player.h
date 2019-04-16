#pragma once
#include "Input.h"
#include "Graphics.h"
#include "Level.h"
#include <string>

class Player {
private:
    double speed;
    sf::Texture player_texture;
    sf::Sprite appearance;
public:
    float posX;
    float posY;
    Player(std::string path, float initX, float initY, double initSpeed);
    ~Player();
    void move(Level* scene, Input* input, double deltatime);
    void draw(Graphics* gfx);
};
