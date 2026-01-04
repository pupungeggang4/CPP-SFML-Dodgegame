#include <scene.hpp>
#include <game.hpp>
#include <field.hpp>
#include <player.hpp>

Scene::Scene() {

}

void Scene::loop(shared_ptr<Game> game) {
    if (!game->gameOver) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
            game->player->rect.position.x -= game->player->speed * game->delta;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
            game->player->rect.position.x += game->player->speed * game->delta;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
            game->player->rect.position.y -= game->player->speed * game->delta;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
            game->player->rect.position.y += game->player->speed * game->delta;
        }
        game->field->handleTick(game);
        game->elapsedTime += game->delta;
        game->score = int(game->elapsedTime);
    } else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Enter)) {
            game->gameOver = false;
            game->elapsedTime = 0;
            game->score = 0;
            game->player->rect.position = sf::Vector2f({400.f, 300.f});
            game->field->bulletList = {};
            game->field->bulletSpawnLeft = 1.5f;
        }
    }
    render(game);
}

void Scene::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::Black);
    game->player->render(game);
    game->field->render(game);
    if (!game->gameOver) {
        game->text.setString("Score: " + std::to_string(game->score));
    } else {
        game->text.setString("Game Over Score: " + std::to_string(game->score) + " Press Enter to Restart.");
    }
    game->window.draw(game->text);
    game->window.display();
}