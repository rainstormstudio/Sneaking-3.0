#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>

#define KEY_TOTAL sf::Keyboard::Return - sf::Keyboard::Unknown + 1

class Input{
private:
    bool prevKey[KEY_TOTAL];
    bool keyPressed[KEY_TOTAL];
    bool keyReleased[KEY_TOTAL];
public:
    Input();
    ~Input();
    bool isKeyPressed(sf::Keyboard::Key key);
    bool isKeyReleased(sf::Keyboard::Key key);
    void update();
};
