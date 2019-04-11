#include "Player.h"

Player::Player(std::string path, float initX, float initY, double initSpeed){
    if (!player_image.loadFromFile(path))
        std::cout << "the player image is failed to load\n";
    player_texture.loadFromImage(player_image);
    appearance.setTexture(player_texture);
    int block_width = 354 / 25, block_height = 574 / 25;
    sf::IntRect rect(block_width * 8, block_height * 0, block_width, block_height);
    appearance.setTextureRect(rect);
    appearance.setScale(3, 3);
    appearance.setOrigin(block_width / 2, block_height);
    posX = initX;
    posY = initY;
    speed = initSpeed;
    appearance.setPosition(posX, posY);
}

Player::~Player(){}

void Player::move(Level* scene, Input* keys, double deltatime){
    float prev_x = posX, prev_y = posY;
    if (keys->isKeyPressed(sf::Keyboard::A))
        posX -= speed * deltatime;
    if (keys->isKeyPressed(sf::Keyboard::D))
        posX += speed * deltatime;
    if (keys->isKeyPressed(sf::Keyboard::W))
        posY -= speed * deltatime;
    if (keys->isKeyPressed(sf::Keyboard::S))
        posY += speed * deltatime;
    appearance.setPosition(posX, posY);
}

void Player::draw(Graphics* gfx){
    gfx->window->draw(appearance);
}
