#pragma once
#include <general.hpp>

class Game;
class Bullet;

class Field {
    public:
        float bulletSpawnInterval = 1.5f, bulletSpawnLeft = 1.5f;
        std::vector<shared_ptr<Bullet>> bulletList = {};
        Field();
        void handleTick(shared_ptr<Game>);
        void spawnBullet();
        void render(shared_ptr<Game>);
};