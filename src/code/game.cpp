#include <game.hpp>
#include <scene.hpp>
#include <player.hpp>
#include <field.hpp>

Game::Game() {
    std::srand(std::time(NULL));
    sf::err().rdbuf(NULL);
    window = sf::RenderWindow(sf::VideoMode({1600, 1200}), "Dodge Game");
    window.setVerticalSyncEnabled(true);
    window.setView(view);
    clock = sf::Clock();
    font.setSmooth(false);
    text.setPosition({20.f, 20.f});
    text.setFillColor(sf::Color::Yellow);
}

void Game::run() {
    self = shared_from_this();
    scene = make_shared<Scene>();
    player = make_shared<Player>();
    field = make_shared<Field>();
    framePrevious = 0.f;
    loop();
}

void Game::loop() {
    while (window.isOpen()) {
        frameCurrent = clock.getElapsedTime().asSeconds();
        delta = frameCurrent - framePrevious;
        framePrevious = frameCurrent;

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        scene->loop(self);
    }
}