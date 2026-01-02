#include <general.hpp>
#include <game.hpp>

int main(int argc, char** argv) {
    sf::err().rdbuf(NULL);
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "Dodge Game");

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.display();
    }
}
