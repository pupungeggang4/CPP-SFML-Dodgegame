#pragma once
#include <general.hpp>

class Game;
class Player {
    public:
        sf::FloatRect rect = sf::FloatRect({400.f, 300.f}, {80.f, 80.f});
        sf::RectangleShape rectS = sf::RectangleShape({80.f, 80.f});
        float speed = 320.f;
        Player();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};