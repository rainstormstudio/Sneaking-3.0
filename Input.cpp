#include "Input.h"

Input::Input(){
    update();
}

Input::~Input(){}

bool Input::isKeyPressed(sf::Keyboard::Key key){
    return keyPressed[key];
}

bool Input::isKeyReleased(sf::Keyboard::Key key){
    return keyReleased[key];
}

void Input::update(){
    for (int i = sf::Keyboard::Unknown; i <= sf::Keyboard::Return; i++){
        sf::Keyboard::Key key = static_cast<sf::Keyboard::Key>(i);
        if (sf::Keyboard::isKeyPressed(key)){
            prevKey[i] = keyPressed[i];
            keyPressed[i] = true;
            keyReleased[i] = false;
        }
        else{
            prevKey[i] = keyPressed[i];
            keyPressed[i] = false;
            keyReleased[i] = prevKey[i];
        }
    }
}
