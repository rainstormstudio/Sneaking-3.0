#include "Game.h"
#include <iostream>

Game::Game(){
    screen_width = 800;
    screen_height = 600;
    FPS = 60;

    show_FPS = true;

    gfx = new Graphics(screen_width, screen_height);
    gfx->window->setFramerateLimit(FPS);
    clock = new sf::Clock();
    input = new Input();

    scene = new Level();
    scene->load_level("Levels/forestmap.png");

    bool main_loop = true;
    while (main_loop && gfx->window->isOpen()){
        sf::Event event;
        while (gfx->window->pollEvent(event)){
            if (event.type == sf::Event::Closed)
                gfx->window->close();
        }

        sf::Time time = clock->getElapsedTime();
        double delta = clock->restart().asMicroseconds();

        update(delta);
        render(delta);
    }
}

Game::~Game(){}

void Game::update(double delta){
    input->update();
}

void Game::render(double delta){
    gfx->clear();
    scene->draw(gfx);

    if (show_FPS){
        gfx->drawText("FPS " + std::to_string(1e6f / delta), sf::Color::White, 16, "font/arial.ttf", 5, 5);
    }
    gfx->render();
}
