#include <general.hpp>
#include <game.hpp>

int main(int argc, char** argv) {
    shared_ptr<Game> game = make_shared<Game>();
    game->run();
}
