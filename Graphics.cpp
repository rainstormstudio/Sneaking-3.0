#include "Graphics.h"

Graphics::Graphics(int initWidth, int initHeight){
    screen_height = initHeight;
    screen_width = initWidth;
    window = new sf::RenderWindow(sf::VideoMode(screen_width, screen_height), "Sneaking version 3.0 rebuilt");
    clear();
    render();
}

Graphics::~Graphics(){}

void Graphics::drawText(std::string caption, sf::Color color, unsigned int size, std::string font_path, float x, float y){
    sf::Text text;
    text.setString(caption);
    text.setFillColor(color);
    text.setCharacterSize(size);
    sf::Font font;
    if (!font.loadFromFile(font_path))
        std::cout << "Error loading font\n";
    text.setFont(font);
    text.setPosition(x, y);
    window->draw(text);
}

void Graphics::clear(){
    window->clear();
}

void Graphics::render(){
    window->display();
}
