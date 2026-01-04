#include <field.hpp>
#include <bullet.hpp>
#include <game.hpp>

Field::Field() {

}

void Field::handleTick(shared_ptr<Game> game) {
    if (bulletSpawnLeft <= 0.f) {
        bulletSpawnLeft = bulletSpawnInterval;
        spawnBullet();
    } else {
        bulletSpawnLeft -= game->delta;
    }

    for (int i = 0; i < bulletList.size(); i++) {
        bulletList[i]->handleTick(game);
    }

    for (int i = bulletList.size() - 1; i >= 0; i--) {
        if (bulletList[i]->rect.position.x < -40 || bulletList[i]->rect.position.x > 840 || bulletList[i]->rect.position.y < -40 || bulletList[i]->rect.position.y > 640) {
            bulletList.erase(bulletList.begin() + i);
        }
    }
}

void Field::render(shared_ptr<Game> game) {
    for (int i = 0; i < bulletList.size(); i++) {
        bulletList[i]->render(game);
    }
}

void Field::spawnBullet() {
    int direction = std::rand() % 4;
    shared_ptr<Bullet> bullet = make_shared<Bullet>();

    if (direction % 2 == 0) {
        bullet->rect.position.y = 20 + std::rand() % 560;
        if (direction == 0) {
            bullet->rect.position.x = -20;
            bullet->velocity = sf::Vector2f({std::rand() % 150 + 100, 0.f});
        } else {
            bullet->rect.position.x = 820;
            bullet->velocity = sf::Vector2f({-(std::rand() % 150) - 100, 0.f});
        }
    } else {
        bullet->rect.position.x = 20 + std::rand() % 760;
        if (direction == 1) {
            bullet->rect.position.y = -20;
            bullet->velocity = sf::Vector2f({0.f, std::rand() % 150 + 100});
        } else {
            bullet->rect.position.y = 620;
            bullet->velocity = sf::Vector2f({0.f, -(std::rand() % 150) - 100});
        }
    }

    bulletList.push_back(bullet);
}