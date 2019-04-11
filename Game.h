#pragma once
#include "Graphics.h"
#include "Input.h"

class Game{
private:
    int screen_width;
    int screen_height;
    int FPS;

    Graphics* gfx;
    Input* input;
    sf::Clock* clock;

    bool show_FPS;

public:
    Game();
    ~Game();
    void update(double delta);
    void render(double delta);
};
