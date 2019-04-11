#pragma once
#include "Graphics.h"
#include "Input.h"
#include "Level.h"

class Game{
private:
    int screen_width;
    int screen_height;
    int FPS;

    Graphics* gfx;
    Input* input;
    sf::Clock* clock;

    Level* scene;

    bool show_FPS;

public:
    Game();
    ~Game();
    void update(double delta);
    void render(double delta);
};
