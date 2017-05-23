#include <iostream>

#include "simple_engine/config.h"
#include "simple_engine/game.h"

#include "test_game/screen/test_game_screen_manager.h"

int main(int argc, char** argv) {
	simple_engine::Config *config = new simple_engine::Config();
	config->addInt("width", 1024);
	config->addInt("height", 768);

	config->addBool("fullscreen", false);

	config->addStr("name", "Test name!");

	config->addInt("static_frame_rate", 60);

	simple_engine::Config::initInstance(config);

	simple_engine::Game &game = simple_engine::Game::initInstance(
			new test_game::TestGameScreenManager()
		);
	game.init();

	return game.run();
}