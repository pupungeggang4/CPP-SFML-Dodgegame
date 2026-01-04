#pragma once
#include <general.hpp>

class Scene;
class Field;
class Player;

class Game : public std::enable_shared_from_this<Game> {
    public:
        shared_ptr<Game> self;
        sf::RenderWindow window; sf::Clock clock;
        sf::Font font = sf::Font("asset/font/neodgm.ttf");
        sf::Text text = sf::Text(font, "", 32);
        sf::View view = sf::View({400.f, 300.f}, {800.f, 600.f});
        float frameCurrent, framePrevious, delta;
        int score = 0; float elapsedTime = 0; bool gameOver = false;

        shared_ptr<Scene> scene;
        shared_ptr<Field> field;
        shared_ptr<Player> player;
        Game();
        void run();
        void loop();
};