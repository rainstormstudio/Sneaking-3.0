#include "Player.h"

Player::Player(std::string path, float initX, float initY, double initSpeed){
    if (!player_texture.loadFromFile(path))
        std::cout << "the player texture is failed to load\n";
    appearance.setTexture(player_texture);
    int block_width = 354 / 24, block_height = 574 / 25;
    posX = initX;
    posY = initY;
    appearance.setOrigin(block_width / 2, block_height);
    sf::IntRect block(block_width * 8, 0, block_width, block_height);
    appearance.setTextureRect(block);
    appearance.setScale(3, 3);
    appearance.setPosition(posX, posY);
    speed = initSpeed;
}

Player::~Player(){}

void Player::move(Level* scene, Input* input, double deltatime){
    if (input->isKeyPressed(sf::Keyboard::A))
        posX -= speed * deltatime;
    if (input->isKeyPressed(sf::Keyboard::D))
        posX += speed * deltatime;
    if (input->isKeyPressed(sf::Keyboard::W))
        posY -= speed * deltatime;
    if (input->isKeyPressed(sf::Keyboard::S))
        posY += speed * deltatime;
    appearance.setPosition(posX, posY);
}

void Player::draw(Graphics* gfx){
    gfx->window->draw(appearance);
}
