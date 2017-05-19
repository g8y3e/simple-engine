#include <iostream>

#include <test_game/test_game.h>

int main(int argc, char** argv) {
	test_game::TestGame game;
	game.init();

	return game.run();
}