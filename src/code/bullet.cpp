#include <bullet.hpp>
#include <player.hpp>
#include <game.hpp>

Bullet::Bullet() {
    rectS.setFillColor(sf::Color::White);
    rectS.setPosition(rect.position - rect.size / 2.f);
}

void Bullet::handleTick(shared_ptr<Game> game) {
    rect.position += velocity * game->delta;
    if ((rect.position - game->player->rect.position).length() < 60.f) {
        game->gameOver = true;
    }
}

void Bullet::render(shared_ptr<Game> game) {
    rectS.setPosition(rect.position - rect.size / 2.f);
    game->window.draw(rectS);
}