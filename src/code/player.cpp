#include <player.hpp>
#include <game.hpp>

Player::Player() {
    rectS.setPosition(rect.position - rect.size / 2.f);
    rectS.setFillColor(sf::Color::Cyan);
}

void Player::handleTick(shared_ptr<Game> game) {

}

void Player::render(shared_ptr<Game> game) {
    rectS.setPosition(rect.position - rect.size / 2.f);
    game->window.draw(rectS);
}