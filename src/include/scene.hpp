#pragma once
#include <general.hpp>

class Game;
class Scene {
    public:
        Scene();
        void loop(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};