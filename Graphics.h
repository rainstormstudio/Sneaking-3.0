#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Graphics{
public:
    int screen_width;
    int screen_height;
    sf::RenderWindow* window;

    Graphics(int initWidth, int initHeight);
    ~Graphics();

    void drawText(std::string text, sf::Color color, unsigned int size, std::string font_path, float x, float y);
    void clear();
    void render();
};
