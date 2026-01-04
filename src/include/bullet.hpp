#pragma once
#include <general.hpp>

class Game;
class Bullet {
    public:
        sf::FloatRect rect = sf::FloatRect({0.f, 0.f}, {40.f, 40.f});
        sf::RectangleShape rectS = sf::RectangleShape({40.f, 40.f});
        sf::Vector2f velocity = {0.f, 0.f};
        Bullet();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};