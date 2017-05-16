#include <iostream>

#include <simple_base/game.h>

int main(int argc, char** argv) {
	simple_engine::Game game("TestGame");

	return game.run();
}