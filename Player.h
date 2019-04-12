#pragma once
#include "Level.h"
#include "Input.h"
#include "Graphics.h"

class Player{
private:
    double speed;
    sf::Image player_image;
    sf::Texture player_texture;
    sf::Sprite appearance;
public:
    float posX;
    float posY;
    Player(std::string path, float initX, float initY, double initSpeed);
    ~Player();
    void move(Level* scene, Input* keys, double deltatime);
    void draw(Graphics* gfx);
};
